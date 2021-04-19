#include "hairdryer.h"

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

unsigned int Hairdryer::heat_level() const
{
    return static_cast<int>(m_heat_level);
}

void Hairdryer::setHeat_level(Heat_level heat_level)
{
    m_heat_level = heat_level;
}
