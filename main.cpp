#include <iostream>
#include <vector>

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
    hair.setHeat_level(Hairdryer::Heat_level::MEDIUM);
    Monitor monit("monit");
    User us("imie");
    comp.openApp("alaska");
    comp.openApp("maska");
    comp.openApp("waska");

    cout<<"Hair "<<hair<<endl;
    cout<<"Monit "<<monit<<endl;
    cout<<"Comp "<<comp<<endl;

    return 0;
}
