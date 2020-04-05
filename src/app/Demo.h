#ifndef DEMO_H
#define DEMO_H

class Demo
{
public:

    static void loop();
    
    static void show();
    
    static void hide();
    
    static bool isVisible();

	static void setVisible(bool);
private:
    static bool m_visible;
};

#endif