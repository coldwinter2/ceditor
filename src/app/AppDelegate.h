#ifndef APP_DELEGATE_H
#define APP_DELEGATE_H
#include <iostream>
#include <vector>
#include "imgui.h"

using namespace std;
class AppDelegate {
public:
	AppDelegate();
	void onAppCreate();

	void onLoop();

	void onExit();

	const char* getAppTitle();

	virtual ~AppDelegate();
private:
	void showDemo() 
	{
		ImGui::ShowDemoWindow(&show_demo_window);
	}
	bool show_demo_window;
};

#endif