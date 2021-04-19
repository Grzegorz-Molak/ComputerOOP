#pragma once
#include <stack>
#include "electronic.h"
#include "app.h"

using namespace std;

class Monitor : public Electronic
{
public:
    // KONSTRUKTORY **********
    Monitor();
    Monitor(string name);
    //Monitor(const Monitor &monitor_to_copy);
    // KONSTRUKTORY **********
    ~Monitor(); // DESTRUKTOR ************

    double diagonal() const;
    void setDiagonal(double diagonal);

    unsigned int getBrightness() const;
    void setBrightness(unsigned int value);


    void switchPower();
    virtual void openApp(string name);
    virtual void closeApp();


protected:
    double m_diagonal = 25;
    unsigned int m_brightness = 50;
    stack<App> m_apps;

private:
   static int m_quantity;
};


