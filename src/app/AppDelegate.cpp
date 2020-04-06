#include "AppDelegate.h"
#include "MainUI.h"
#include "OpenDialog.h"

AppDelegate* AppDelegate::m_instance = nullptr;

AppDelegate* AppDelegate::getInstance()
{
	if(AppDelegate::m_instance == nullptr)
	{
		AppDelegate::m_instance = new (std::nothrow) AppDelegate();
	}
	return AppDelegate::m_instance;
}

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

	MainUI::loop();
	Demo::loop();
	OpenDialog::loop();
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