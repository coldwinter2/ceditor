#include "MainUI.h"
#include "Demo.h"
#include "OpenDialog.h"

bool MainUI::m_dock_open = false;

void MainUI::loop()
{
	ImGuiWindowFlags window_flags = 0;
	window_flags |= ImGuiWindowFlags_MenuBar;
	window_flags |= ImGuiWindowFlags_NoDocking;

	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->GetWorkPos());
	ImGui::SetNextWindowSize(viewport->GetWorkSize());
	ImGui::SetNextWindowViewport(viewport->ID);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	//ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	//ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

	ImGui::Begin("ceditor", &m_dock_open, window_flags);
	ImGui::PopStyleVar();
	//ImGui::PopStyleVar(3);
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open...", "CTRL+O", false))
				{
					OpenDialog::ShowOpen({ "a","b" }, [](string& s) {
						if(s != "")
							printf("path:%s\n", s.c_str());
					});
				}
				if (ImGui::MenuItem("Exit", "CTRL+E", false))
				{
					AppDelegate::getInstance()->exit();
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		if (ImGui::Button(Demo::isVisible() ? "hide demo" : "show demo"))
		{
			
		}
	}

	ImGui::End();
}