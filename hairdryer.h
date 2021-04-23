#pragma once
#include "electronic.h"
#include <string>

class Hairdryer : public Electronic
{
public:
    enum class Heat_level { OFF ,LOW, MEDIUM, HIGH};
    Hairdryer();
    Hairdryer(string name);
    ~Hairdryer();

    void switchPower();
    int heat_level();
    void setHeat_level(Heat_level heat_level);

    void save();
    void save(ostream& file);

    void read();
    void read(istream& file);

    friend ostream & operator<<( ostream &s , Hairdryer& hairdryer);
    friend istream & operator>>( istream &s , Hairdryer& hairdryer);
    friend ostream & operator>>( ostream &s , Hairdryer::Heat_level& heat_level);
//private:
    Heat_level m_heat_level = Heat_level::OFF;
   static int m_quantity;
};

