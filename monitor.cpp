#include "monitor.h"
#include <fstream>

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

ostream & operator<<( ostream &s , const Monitor& monitor)
{
    s << *(dynamic_cast<const Electronic*>(&monitor));
    s << " | " << monitor.m_diagonal <<" | "<< monitor.m_brightness;

stack<App> apps = monitor.m_apps;
if(apps.empty()) {cout<<" | BRAK"<<endl; return s;}
else
{
    while(!apps.empty())
    {
        s<<" | "<<apps.top();
        apps.pop();
    }
}
return s;
}

istream & operator>>( istream &s , Monitor& monitor)
{
return s >> monitor.m_brightness;
}

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

void Monitor::save()
{
    ofstream file;
    file.open(m_name+".txt", ios_base::out);
    save(file);
    file.close();
}

void Monitor::save(ostream& file)
{
    Electronic::save(file);
    file << " | " << m_diagonal <<" | "<< m_brightness;

    stack<App> apps = m_apps;
    if(apps.empty()) cout<<" | BRAK"<<endl;
    else
    {
        while(!apps.empty())
        {
            file<<" | "<<apps.top();
            apps.pop();
        }
    }
}


void Monitor::openApp(string name)
{
#ifdef _DEBUG
    cout<<"Calling openApp in Monitor class"<<endl;
#endif
    if(m_power)
    {
    this->m_apps.pop();
    this->m_apps.emplace(name);
    }
    else
    {
        if(askToTurnOn())
        {
            switchPower();
            openApp(name);
        }
    }
}

void Monitor::closeApp()
{
#ifdef _DEBUG
    cout<<"Calling closeApp in Monitor class"<<endl;
#endif
    if(m_power)
    {
        this->m_apps.pop();
        if(m_apps.empty())
        {
            this->m_apps.emplace("Hello World");
        }
    }
    else
    {
        cout<<"Monitor jest wylaczony, nie ma zadnych otwartych afileacji"<<endl;
    }

}






// OPERATORY ******************************************
