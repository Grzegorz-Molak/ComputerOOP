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
    cout<<c<<endl;
    c.swap(2,1);
    cout<<c<<endl;
    c.push_back(3);
    cout<<c<<endl;
    c.swap(1,3);
    cout<<c<<endl;
    c.swap(1,2);
    cout<<c<<endl;
    c.swap(2,3);
    cout<<c<<endl;
    c.push_back(4);
    c.push_back(5);
    cout<<c<<endl;
    c.swap(4,5);
    cout<<c<<endl;
    c.swap(2,3);
    cout<<c<<endl;


    /*Container<string> s;
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
    cout<<d<<endl;*/

    return 0;
}
