#include "hairdryer.h"
#include "useful.h"
#include <fstream>

int Hairdryer::m_quantity = 0;


// KONSTRUKTORY I DESTRUKTORY ***********************
Hairdryer::Hairdryer()
{
    this->m_quantity++;
#ifdef _DEBUG
    cout<<"Hairdryer("<<m_name<<"), 'Hairdryer' objects: "<<m_quantity<<endl;
#endif
}


Hairdryer::Hairdryer(string name) : Hairdryer()
{
    m_name = name;
}

Hairdryer::~Hairdryer()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Hairdryer(), 'Hairdryer' objects: "<<m_quantity<<endl;
#endif
}

// KONSTRUKTORY I DESTRUKTORY ***********************


// OPERATORY ****************************************
istream & operator>>(istream &s, Hairdryer::Heat_level& heat_level)
{
    int h;
    s>>h;
    heat_level = static_cast<Hairdryer::Heat_level>(h);
    return s;
}

ostream & operator<<( ostream &s , Hairdryer& hairdryer)
{
    s<<*(dynamic_cast<Electronic*>(&hairdryer));
    s<<"Poziom-ciepla: ";
    switch(static_cast<int>(hairdryer.m_heat_level))
    {
        case 0:
            s<<"OFF ";
            break;
        case 1:
            s<<"LOW ";
            break;
        case 2:
            s<<"MEDIUM ";
            break;
        case 3:
            s<<"HIGH ";
            break;

    }
    s<<static_cast<int>(hairdryer.m_heat_level)<<endl;
    return s;
}

istream & operator>>( istream &s , Hairdryer& hairdryer)
{
    string title;
    s>>*(dynamic_cast<Electronic*>(&hairdryer));
    s>>title>>title>>hairdryer.m_heat_level;
    return s;
}
// OPERATORY ****************************************

// INNE FUNKCJE *************************************
void Hairdryer::switchPower()
{
#ifdef _DEBUG
    cout<<"Calling switchPower in Hairdryer class"<<endl;
#endif
    if(this->m_power == false)
    {
        cout<<"Wlaczam suszarke, ustawiam cieplo na LOW"<<endl;
        this->m_power = true;
        this->m_heat_level = Heat_level::LOW;
    }
    else
    {
        cout<<"Wylaczam suszarke, ustawiam cieplo na OFF"<<endl;
        this->m_power = false;
        this->m_heat_level = Heat_level::OFF;
    }
}

void Hairdryer::save()
{
    ofstream file;
    file.open(m_name+".txt");
    if(file)
    {
        cout<<"Udalo sie otworzyc file"<<endl;
        file<<"Hairdryer"<<endl;
        file<<*this;
        file.close();
    }

    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

}

int Hairdryer::read()
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
        if(namefile == "Hairdryer")
        {
            file>>*this;
        }
        else
        {
            cout<<"Do suszarki moze byc przypisana tylko suszarka"<<endl;
            return 0;
        }

        file.close();
        return 1;
    }
    else
    {
        cout<<"nie udalo sie otworzyc pliku"<<endl;
        return 0;
    }
}

void Hairdryer::print()
{
   cout<<*this;
}

void Hairdryer::edit()
{
    Electronic::edit();
    if(m_power == 1)
    {
        cout<<"Wybierz poziom ciepla: "<<endl;
        cout<<"0. OFF "<<endl;
        cout<<"1. LOW "<<endl;
        cout<<"2. MEDIUM "<<endl;
        cout<<"3. HIGH"<<endl;
        switch(getInt(0,3))
        {
            case 0:
                m_heat_level = Hairdryer::Heat_level::OFF;
                break;
            case 1:
                m_heat_level = Hairdryer::Heat_level::LOW;
                break;
            case 2:
                m_heat_level = Hairdryer::Heat_level::MEDIUM;
                break;
            case 3:
                m_heat_level = Hairdryer::Heat_level::HIGH;
                break;
        }
    }
}

int Hairdryer::functions()
{
    Electronic::functions();
    cout<<"2. Zmiana poziomu ciepla"<<endl;
    return 1;
}

// INNE FUNKCJE *************************************
// SETTERSY I GETTERSY ************

int Hairdryer::heat_level()
{
    return static_cast<int>(m_heat_level);
}

void Hairdryer::setHeat_level()
{
    cout<<"Wybierz poziom ciepla: "<<endl;
    cout<<"0. OFF "<<endl;
    cout<<"1. LOW "<<endl;
    cout<<"2. MEDIUM "<<endl;
    cout<<"3. HIGH"<<endl;

    switch(getInt(0,3))
    {
        case 0:
            setHeat_level(Hairdryer::Heat_level::OFF);
            break;
        case 1:
            setHeat_level(Hairdryer::Heat_level::LOW);
            break;
        case 2:
            setHeat_level(Hairdryer::Heat_level::MEDIUM);
            break;
        case 3:
            setHeat_level(Hairdryer::Heat_level::HIGH);
            break;

    }
}

void Hairdryer::setHeat_level(Heat_level heat_level)
{
    if(m_power)
    {
       m_heat_level = heat_level;
    }
    else
    {
        if(askToTurnOn())
        {
            switchPower();
            setHeat_level(heat_level);
        }
    }

}

// SETTERSY I GETTERSY ************
