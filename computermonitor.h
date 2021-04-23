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

    Output output();
    void setOutput(Output output);

    void save();
    void read();

    friend ostream& operator<<(ostream &, const ComputerMonitor&);
    friend istream & operator>>( istream &s , ComputerMonitor& computermonitor);
    friend istream & operator>>( istream &s , ComputerMonitor::Output& output);

protected:
    Output m_output = Output::VGA;

private:
   static int m_quantity;
};
