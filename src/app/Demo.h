#ifndef DEMO_H
#define DEMO_H

class Demo
{
public:
    Demo();
       
    virtual void loop();
    
    virtual void show();
    
    virtual void hide();
    
    virtual bool isVisible();

	virtual void setVisible(bool);
private:
    bool m_visible;
};

#endif