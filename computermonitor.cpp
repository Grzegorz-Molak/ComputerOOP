#include "computermonitor.h"
#include "useful.h"
#include <fstream>


int ComputerMonitor::m_quantity = 0;

// KONSTRUKTORY I DESTRUKTORY ***********************
ComputerMonitor::ComputerMonitor()
{
    this->m_quantity++;
#ifdef _DEBUG
    cout<<"ComputerMonitor("<<m_name<<"), 'ComputerMonitor' objects: "<<m_quantity<<endl;
#endif
}

ComputerMonitor::ComputerMonitor(string name) : ComputerMonitor()
{
    m_name = name;
}

ComputerMonitor::ComputerMonitor(string name, Output output) : ComputerMonitor()
{
    m_name = name;
    m_output = output;
}

ComputerMonitor::~ComputerMonitor()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~ComputerMonitor(), 'ComputerMonitor' objects: "<<this->m_quantity<<endl;
#endif
}
// KONSTRUKTORY I DESTRUKTORY ***********************

// OPERATORY ****************************************
ostream & operator<<( ostream &s , const ComputerMonitor& computermonitor)
{
    s << *(dynamic_cast<const Monitor*>(&computermonitor));
    //s<< "Wyjscie: " << static_cast<int>(computermonitor.m_output)<<endl;
    s<<"Output: ";
    switch(static_cast<int>(computermonitor.m_output))
    {
        case 0:
            s<<"VGA ";
            break;
        case 1:
            s<<"DVI ";
            break;
        case 2:
            s<<"HDMI ";
            break;
        case 3:
            s<<"DISPLAYPORT ";
            break;

     }
    s<<static_cast<int>(computermonitor.m_output)<<endl;
    return s;
}
istream & operator>>( istream &s , ComputerMonitor& computermonitor)
{
    string title;
    s >> *(dynamic_cast<Monitor*>(&computermonitor));
    s >>title>>title>> computermonitor.m_output;
    return s;
}
istream & operator>>( istream &s , ComputerMonitor::Output& output)
{
    string title;
    int o;
    s>>o;
    cout<<o<<endl;
    output = static_cast<ComputerMonitor::Output>(o);
    return s;
}
// OPERATORY ****************************************

// INNE FUNKCJE *************************************
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
        while(!m_apps.empty())
        {
            m_apps.pop();
        }
    }
}

void ComputerMonitor::openApp(string name)
{

#ifdef _DEBUG
    cout<<"Calling openApp in ComputerMonitor class, opening "<<name<<endl;
#endif
    if(m_power)
    {
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

void ComputerMonitor::save()
{
    ofstream file;
    file.open(m_name+".txt");
    if(file)
    {
        cout<<"Udalo sie utworzyc plik"<<endl;
        file<<*this;
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

}
void ComputerMonitor::read()
{
    string namefile;
    ifstream file;
    cout<<"Prosze podac nazwe pliku: "<<endl;
    cin>>namefile;
    file.open(namefile, ios_base::in);
    if(file)
    {
        cout<<"udalo sie otworzyc plik"<<endl;
        file>>*this;
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return;
    }

}

void ComputerMonitor::print()
{
   cout<<*this;
}

void ComputerMonitor::edit()
{
Monitor::edit();
if(m_power == 1)
{
    cout<<"Nowy output: "<<endl;
    switch(getInt(0,3))
    {
        case 0:
            m_output = ComputerMonitor::Output::VGA;
            break;
        case 1:
            m_output = ComputerMonitor::Output::DVI;
            break;
        case 2:
            m_output = ComputerMonitor::Output::HDMI;
            break;
        case 3:
            m_output = ComputerMonitor::Output::DISPLAYPORT;
            break;

    }
}
}

ComputerMonitor::Output ComputerMonitor::output()
{
return m_output;
}
void ComputerMonitor::setOutput(Output output)
{
m_output = output;
}

