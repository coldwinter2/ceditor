#include "Demo.h"
#include "imgui.h"


bool Demo::m_visible = true;

void Demo::loop()
{
    if(m_visible)
		ImGui::ShowDemoWindow(&m_visible);
}

void Demo::show()
{
    m_visible = true;
}

void Demo::hide()
{
    m_visible = false;
}

bool Demo::isVisible()
{
    return m_visible;
}

void Demo::setVisible(bool visible)
{
	m_visible = visible;
}