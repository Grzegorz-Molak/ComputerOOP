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
    s<<"Output: ";
    switch(static_cast<int>(computermonitor.m_output)) // Wybiera odpowiedni Output
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
    s >> *(dynamic_cast<Monitor*>(&computermonitor)); // wywołuje strumień klasy bazowej
    s >>title>>title>> computermonitor.m_output; // swój element pobiera
    return s;
}
istream & operator>>( istream &s , ComputerMonitor::Output& output)
{
    string title;
    int o;
    s>>o;
    cout<<o<<endl;
    output = static_cast<ComputerMonitor::Output>(o); // zmienia liczbe na output
    return s;
}
// OPERATORY ****************************************

// INNE FUNKCJE *************************************
void ComputerMonitor::switchPower()
{
    if(this->m_power == false)
    {
        cout<<"Wlaczam monitor komputerowy, otwieram standardowa aplikacje Hello World"<<endl;
        this->m_power = true;
        this->m_apps.emplace("Hello world");
    }
    else
    {
        cout<<"Wylaczam monitor komputerowy, zamykam wszystkie aplikacje"<<endl;
        this->m_power = false;
        while(!m_apps.empty())
        {
            m_apps.pop();
        }
    }
}

void ComputerMonitor::openApp(string name)
{
    cout<<"Otwieram nowa aplikacje: "<<name<<endl;
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
        file<<"ComputerMonitor"<<endl;
        file<<*this;
        file.close();
    }
    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

}
int ComputerMonitor::read()
{
    string namefile;
    ifstream file;
    cout<<"Prosze podac nazwe pliku: "<<endl;
    cin>>namefile;
    file.open(namefile, ios_base::in);
    if(file)
    {
        cout<<"udalo sie otworzyc plik"<<endl;
        file>>namefile;
        if(namefile == "ComputerMonitor")
        {
        file>>*this;
        }
        else if(namefile == "Monitor")
        {
            file>>*(dynamic_cast<Monitor*>(this));
        }
        else
        {
            cout<<"Do komputera monitorowego mozna przypisac tylko monitor lub monitor komputerowy"<<endl;
            return 0;
        }
        file.close();
        return 1;
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return 0;
    }

}

void ComputerMonitor::print()
{
   cout<<*this;
}

void ComputerMonitor::edit()
{
    Monitor::edit(); // wywołuje edytor klasy bazowej
    if(m_power == 1)
    {
        cout<<"Wybierz output: "<<endl;
        cout<<"0. VGA"<<endl;
        cout<<"1. DVI"<<endl;
        cout<<"2. HDMI"<<endl;
        cout<<"3. DISPLAYPORT"<<endl;
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

int ComputerMonitor::functions()
{
    Monitor::functions(); // funkcje klasy bazowej
    cout<<"4. Zmien output"<<endl;
    return 3;
}

// INNE FUNKCJE *******************
// SETTERSY I GETTERSY ************

ComputerMonitor::Output ComputerMonitor::output()
{
    return m_output;
}

void ComputerMonitor::setOutput()
{
    cout<<"Wybierz output: "<<endl;
    cout<<"0. VGA"<<endl;
    cout<<"1. DVI"<<endl;
    cout<<"2. HDMI"<<endl;
    cout<<"3. DISPLAYPORT"<<endl;

    switch(getInt(0,3))
    {
        case 0:
            setOutput(ComputerMonitor::Output::VGA);
            break;
        case 1:
            setOutput(ComputerMonitor::Output::DVI);
            break;
        case 2:
            setOutput(ComputerMonitor::Output::HDMI);
            break;
        case 3:
            setOutput(ComputerMonitor::Output::DISPLAYPORT);
            break;

    }
}
void ComputerMonitor::setOutput(Output output)
{
    if(m_power)
    {
       m_output = output;
    }
    else
    {
        if(askToTurnOn())
        {
            switchPower();
            setOutput(output);
        }
    }
}

// SETTERSY I GETTERSY

