#include <iostream>
#include <vector>

#include "container.h"
#include "computermonitor.h"
using namespace std;


int main()
{
   // interface();
    Container<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push(3,3);
    c.push(4,20);
    cout<<c<<endl;
    c.pop(3);
    //c.push(8,12);
    cout<<c<<endl;
    c.pop_back();
    cout<<c<<endl;

    Container<string> s;
    s.push_back("kssks");
    s.push_back("blelbel");
    s.push_back("ddfsdf");
    s.push(2, "kcici");
    cout<<s<<endl;
    s.pop(2);
    cout<<s<<endl;

    Container<ComputerMonitor> d;
    ComputerMonitor maciek("maciek");
    ComputerMonitor maciek2("maciek2");
    d.push_back(maciek);
    d.push_back(maciek2);
    cout<<d<<endl;

    return 0;
}
