#include "computermonitor.h"
#include <fstream>


int ComputerMonitor::m_quantity = 0;

// KONSTRUKTORY I DESTRUKTORY ***********************
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
// KONSTRUKTORY I DESTRUKTORY ***********************

// OPERATORY ****************************************
ostream & operator<<( ostream &s , const ComputerMonitor& computermonitor)
{

    s << static_cast<Monitor>(computermonitor);
    s<< "Wyjscie: " << static_cast<int>(computermonitor.m_output);
    return s;
}
istream & operator>>( istream &s , ComputerMonitor& computermonitor)
{
return s >> computermonitor.m_output;
}
istream & operator>>( istream &s , ComputerMonitor::Output& output)
{
    int o;
    s>>o;
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
        save(file);
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

}
void ComputerMonitor::save(ostream& file)
{
    Monitor::save(file);
    file<< "Wyjscie: " << static_cast<int>(m_output);
    //file<<*this;
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
        read(file);
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return;
    }

}

void ComputerMonitor::read(istream& file)
{
    Monitor::read(file);
    string title;
    file>>title;
    if(title == "Wyjscie:") file>>m_output;

}

ComputerMonitor::Output ComputerMonitor::output()
{
return m_output;
}
void ComputerMonitor::setOutput(Output output)
{
m_output = output;
}

