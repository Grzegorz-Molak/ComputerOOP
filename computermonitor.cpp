#include "computermonitor.h"

int ComputerMonitor::m_quantity = 0;

ComputerMonitor::ComputerMonitor()
{
    this->m_quantity++;
}

ComputerMonitor::ComputerMonitor(string name) : ComputerMonitor()
{
    m_name = name;
#ifdef _DEBUG
    cout<<"ComputerMonitor("<<name<<"), 'ComputerMonitor' objects: "<<m_quantity<<endl;
#endif
}

ComputerMonitor::ComputerMonitor(string name, Output output) : ComputerMonitor()
{
    m_name = name;
    m_output = output;
#ifdef _DEBUG
    cout<<"ComputerMonitor("<<name<<","<<static_cast<int>(output)<<"), 'ComputerMonitor' objects: "<<m_quantity<<endl;
#endif
}

ComputerMonitor::~ComputerMonitor()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~ComputerMonitor()"<<endl;
#endif
}
void ComputerMonitor::switchPower()
{
#ifdef _DEBUG
    cout<<"Calling switchPower in ComputerMonitor class"<<endl;
#endif
    if(this->m_power == false)
    {
        this->m_power = true;
        this->m_apps.emplace("Hello world");
    }
    else
    {
        this->m_power = false;
        for(size_t i = 0; i < m_apps.size(); i++)
        {
            this->m_apps.pop();
        }
    }
}

void ComputerMonitor::openApp(string name)
{
#ifdef _DEBUG
    cout<<"Calling openApp in ComputerMonitor class, opening "<<name<<endl;
#endif
    this->m_apps.emplace(name);
}

void ComputerMonitor::closeApp()
{
#ifdef _DEBUG
    cout<<"Calling closeApp in ComputerMonitor class, closing "<<m_apps.top().name()<<endl;
#endif
    if(this->m_apps.size() > 1)
    {

        this->m_apps.pop();
    }
    else
    {
        this->m_apps.pop();
        this->m_apps.emplace("Hello World");
    }
}
