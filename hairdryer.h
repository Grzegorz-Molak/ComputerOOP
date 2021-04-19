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
    unsigned int heat_level() const;
    void setHeat_level(Heat_level heat_level);

protected:
    Heat_level m_heat_level = Heat_level::OFF;

private:
   static int m_quantity;
};

