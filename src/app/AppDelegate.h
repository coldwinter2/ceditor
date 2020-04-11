#ifndef APP_DELEGATE_H
#define APP_DELEGATE_H

#include <iostream>
#include <vector>
#include "imgui.h"
#include "Demo.h"

using namespace std;
class AppDelegate {

private:
	static AppDelegate* m_instance;
	AppDelegate();

public:

	static AppDelegate* getInstance();

	void onAppCreate();

	void onLoop();

	void onExit();


	void exit() { m_app_exit = true; }

	const char* getAppTitle();

	virtual ~AppDelegate();

	bool needExit() {
		return m_app_exit;
	}

	void destroy()
	{
		delete AppDelegate::m_instance;
		AppDelegate::m_instance = nullptr;
	}

protected:
	virtual void onDemoClick();
private:
	bool m_app_exit = false;

	bool m_dock_open;


};



#endif