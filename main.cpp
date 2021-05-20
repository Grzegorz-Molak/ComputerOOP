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
    cout<<"c: \n"<<c<<endl;
    c.swap(2,3);
    cout<<"c: \n"<<c<<endl;

    Container<int> d(c);
    cout<<d<<endl;

    c.swap(1,5);
    d.swap(1,2);

    cout<<"c:\n"<<c<<endl<<"d:\n"<<d<<endl;

    Container<int> e;
    e.push_back(1);
    e.push_back(23);
    e.push_back(4);
    cout<<e<<endl;
    cout<<"eeee\n"<<(e == d)<<endl;

    e = d;

    cout<<e<<endl;
    cout<<"eeee\n"<<(e == d)<<endl;

    d.swap(1,5);

   cout<<"e: "<<endl<<e<<endl<<"d: "<<endl<<d<<endl;


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
