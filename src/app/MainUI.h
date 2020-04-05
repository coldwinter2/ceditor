#ifndef MAINUI_H
#define MAINUI_H
#include "imgui.h"
#include "AppDelegate.h"

class MainUI
{
public:
	static void loop();

private:
	static bool m_dock_open;
    
};
#endif