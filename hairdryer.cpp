#include "hairdryer.h"
#include <fstream>


int Hairdryer::m_quantity = 0;

Hairdryer::Hairdryer()
{
this->m_quantity++;
}

Hairdryer::Hairdryer(string name) : Hairdryer()
{
    m_name = name;
#ifdef _DEBUG
    cout<<"Hairdryer("<<name<<"), 'Hairdryer' objects: "<<m_quantity<<endl;
#endif
}

Hairdryer::~Hairdryer()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Hairdryer(), 'Hairdryer' objects: "<<m_quantity<<endl;
#endif
}

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
 s<<"Poziom-ciepla: "<<static_cast<int>(hairdryer.m_heat_level)<<endl;
 return s;
}
istream & operator>>( istream &s , Hairdryer& hairdryer)
{
    string title;
    s>>*(dynamic_cast<Electronic*>(&hairdryer));
    s>>title>>hairdryer.m_heat_level;
    return s;
}
void Hairdryer::switchPower()
{
#ifdef _DEBUG
    cout<<"Calling switchPower in Hairdryer class"<<endl;
#endif
    if(this->m_power == false)
    {
        this->m_power = true;
        this->m_heat_level = Heat_level::LOW;
    }
    else
    {

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
        file<<*this;
        file.close();
    }

    else
    {
        cout<<"Nie udalo sie utworzyc pliku"<<endl;
        return;
    }

}

void Hairdryer::read()
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
        cout<<"nie udalo sie otworzyc pliku";
        return;
    }
}

int Hairdryer::heat_level()
{
    return static_cast<int>(m_heat_level);
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
