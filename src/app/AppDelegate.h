#ifndef APP_DELEGATE_H
#define APP_DELEGATE_H

#include <iostream>
#include <vector>
#include "imgui.h"
#include "Demo.h"

using namespace std;
class AppDelegate {
public:
	AppDelegate();
	void onAppCreate();

	void onLoop();

	void onExit();


	void exit() { m_app_exit = true; }

	const char* getAppTitle();

	virtual ~AppDelegate();

	bool needExit() {
		return m_app_exit;
	}

protected:
	virtual void onDemoClick();
private:
	bool m_app_exit = false;
	Demo demo;

	bool m_dock_open;
};

#endif