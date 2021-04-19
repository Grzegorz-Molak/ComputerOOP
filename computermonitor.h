#pragma once
#include "app.h"
#include "monitor.h"

class ComputerMonitor : public Monitor
{

public:
    enum class Output { VGA, DVI, HDMI, DISPLAYPORT};
    ComputerMonitor();
    ComputerMonitor(string name);
    ComputerMonitor(string name, Output output);
    ~ComputerMonitor();


    void switchPower();
    void openApp(string name);
    void closeApp();

protected:

    Output m_output = Output::VGA;

private:
   static int m_quantity;
};
