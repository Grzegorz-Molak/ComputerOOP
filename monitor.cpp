#include "monitor.h"

int Monitor::m_quantity = 0;

// KONSTRUKTORY ****************************************
Monitor::Monitor()
{
    this->m_quantity++;
}

Monitor::Monitor(string name) : Monitor()
{
    m_name = name;
#ifdef _DEBUG
    cout<<"Monitor("<<name<<"), 'Monitor' objects: "<<this->m_quantity<<endl;
#endif
}

// KONSTRUKTORY ****************************************

Monitor::~Monitor()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Monitor, 'Monitor' objects: "<<this->m_quantity<<endl;
#endif
}

// OPERATORY ******************************************

double Monitor::diagonal() const
{
    return m_diagonal;
}

void Monitor::setDiagonal(double diagonal)
{
    m_diagonal = diagonal;
}

unsigned int Monitor::getBrightness() const
{
    return m_brightness;
}

void Monitor::setBrightness(unsigned int value)
{
    m_brightness = value;
}

void Monitor::switchPower()
{
#ifdef _DEBUG
    cout<<"Calling switchPower in Monitor class"<<endl;
#endif
    if(this->m_power == false)
    {
        this->m_power = true;
        this->m_apps.emplace("Hello World");
    }
    else
    {
        this->m_power = false;
        this->m_apps.pop();
    }
}

void Monitor::openApp(string name)
{
#ifdef _DEBUG
    cout<<"Calling openApp in Monitor class"<<endl;
#endif
    this->m_apps.pop();
    this->m_apps.emplace(name);
}

void Monitor::closeApp()
{
#ifdef _DEBUG
    cout<<"Calling closeApp in Monitor class"<<endl;
#endif
    this->m_apps.pop();
    this->m_apps.emplace("Hello World");
}


// OPERATORY ******************************************
