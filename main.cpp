#include <iostream>
#include <vector>
#include <fstream>

#include "electronic.h"
#include "monitor.h"
#include "computermonitor.h"
#include "hairdryer.h"

using namespace std;


int main()
{
    /*string cha;
    vector<Electronic*> electronics;
    Hairdryer hair("Messy");
    Monitor monit("Lippy");
    ComputerMonitor comp("Iks de");
    ComputerMonitor comp2("Ikki", ComputerMonitor::Output::DISPLAYPORT);
    electronics.push_back(&hair);
    electronics.push_back(&monit);
    electronics.push_back(&comp);
    electronics.push_back(&comp2);

    for(auto elek : electronics)
    {
        elek->switchPower();
    }

    comp.openApp("Kopciuszek");
    comp.closeApp();*/


    App apka = {"Kotek"};
    ComputerMonitor comp("comp");
    Hairdryer hair("hair");
    Monitor monit("monit");
    User us("imie");
    comp.switchPower();
    monit.switchPower();

    comp.openApp("alaska2");
    comp.openApp("maska2");
    comp.openApp("waska2");
    cout<<"Comp "<<comp<<endl;
    comp.read();
    cout<<"Comp "<<comp<<endl;
    cout<<"Monit "<<monit<<endl;
    monit.read();
    cout<<"Monit "<<monit<<endl;
    cout<<"Hair "<<hair<<endl;
    hair.read();
    cout<<"Hair "<<hair<<endl;


    return 0;
}
