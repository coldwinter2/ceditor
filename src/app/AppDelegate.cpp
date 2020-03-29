#include "AppDelegate.h"

AppDelegate::AppDelegate():
m_app_exit(false)
,m_dock_open(true)
{

}

void AppDelegate::onAppCreate() 
{

}

void AppDelegate::onLoop() 
{
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
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
		if(ImGui::BeginMenuBar())
		{
			if(ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open...", "Ctrl+O", false))
				{

				}
				if (ImGui::MenuItem("Exit", "Ctrl+E", false))
				{
					exit();
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		if (ImGui::Button(demo.isVisible()?"hide demo":"show demo"))
			demo.setVisible(!demo.isVisible());
	}
	
	ImGui::End();

	demo.loop();
}

void AppDelegate::onDemoClick()
{
	cout << "clicked" << endl;
	printf("clicked");

}

void AppDelegate::onExit() 
{

}

const char* AppDelegate::getAppTitle() 
{
	return "Demo";
}

AppDelegate::~AppDelegate()
{
	cout << "Application Exit" << endl;
	printf("Debug info");
}