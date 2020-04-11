#include "OpenDialog.h"


bool OpenDialog::is_visible = false;

OpenDialog::DialogType OpenDialog::show_type = OpenDialog::DialogType::NONE;

OD_CALLBACK OpenDialog::m_callback = nullptr;

struct OpenDialog::Path OpenDialog::m_path;

string OpenDialog::file_selected = "";

string OpenDialog::title = "Open";

bool OpenDialog::is_folder = false;


void OpenDialog::ShowOpen(vector<string> filter, OD_CALLBACK cb)
{
	//initRootPath();
	m_path.init();
	show_type = DialogType::OPEN;
	m_callback = cb;
	is_visible = true;
	file_selected = "";
	title = u8"打开";

}

void OpenDialog::ShowSave(vector<string> filter, OD_CALLBACK cb)
{
	m_path.init();
	show_type = DialogType::SAVE;
	m_callback = cb;
	is_visible = true;
	file_selected = "";
	title = u8"保存";

}

void OpenDialog::SetFolderTarget(bool is_folder)
{
	OpenDialog::is_folder = is_folder;
}


void OpenDialog::loop()
{
	if (is_visible)
	{
		file_selected = "";
		ImGui::OpenPopup(title.c_str());
		is_visible = false;
	}

	if (ImGui::BeginPopupModal(u8"打开",NULL,ImGuiWindowFlags_NoResize ))
	{
#ifdef WIN32
		static int combo_current_id = 0;
		vector<string>& root = m_path.getRoot();
		if (root.size() > 0)
		{
			combo_current_id = min(combo_current_id, root.size() - 1);
			if (ImGui::BeginCombo(u8"驱动器", root[combo_current_id].c_str(), ImGuiWindowFlags_Popup))
			{
				for (int id = 0; id < root.size(); id++)
				{
					if (ImGui::Selectable(root[id].c_str(), id == combo_current_id))
					{
						combo_current_id = id;
						// update folder view
						m_path.changeRoot(id);
					}
				}
				ImGui::EndCombo();
			}
		}
#endif
		ImGui::Separator();
		vector<string>& files = m_path.getFiles();
		if (ImGui::ListBoxHeader("", ImVec2(300, 200)))
		{
			for (int i = 0; i < files.size(); i++)
			{
				bool selected = file_selected == files[i];
				if (ImGui::Selectable(files[i].c_str(), &selected, ImGuiSelectableFlags_AllowDoubleClick))
				{
					file_selected = files[i];
					if (ImGui::IsMouseDoubleClicked(0))
					{
						if (file_selected == "..")
						{
							m_path.back();
						}
						else if(!m_path.enter(files[i]))
						{
							// 选择的是文件
							if (!is_folder)
							{
								confirmed(file_selected);
							}
						}
						file_selected = "";
					}
				}
			}
			ImGui::ListBoxFooter();
		}
		ImGui::Separator();
		ImGui::Text(m_path.getFullpath().c_str());

		ImGui::Separator();
		if (ImGui::Button("OK", ImVec2(120, 0))) 
		{ 
			bool button_enable = false;
			if (file_selected != "")
			{
				button_enable = is_folder ? isFolder(file_selected) : !isFolder(file_selected);
			}
			if(button_enable)
				confirmed(file_selected);
		}
		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0))) 
		{ 
			canceled();
		}
		ImGui::EndPopup();
	}
}

void OpenDialog::confirmed(string& path)
{

	if (m_callback)
	{
		string ret = m_path.getFullpath();
		ret += path;
		m_callback(ret);
		m_callback = nullptr;
	}
	ImGui::CloseCurrentPopup();

}

void OpenDialog::canceled()
{
	if (m_callback)
	{
		string ret = "";
		m_callback(ret);
		m_callback = nullptr;
	}
	ImGui::CloseCurrentPopup();
}

bool OpenDialog::isFolder(string& path)
{
	return path.back() == '/';
}