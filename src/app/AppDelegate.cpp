#include "AppDelegate.h"

AppDelegate::AppDelegate():
show_demo_window(true)
{

}

void AppDelegate::onAppCreate() 
{

}

void AppDelegate::onLoop() 
{
	showDemo();
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
}