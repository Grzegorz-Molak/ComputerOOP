#include <iostream>
#include "monitor.h"

using namespace std;

Monitor m_global = {"GLOBAL", 6};

int test()
{
#ifdef _DEBUG
    cout<<endl;
    Monitor m_test1;
    cout<<endl;
    Monitor m_test2 = {"Asus"};
    cout<<endl;
    Monitor m_test3 = {5};
    cout<<endl;
    Monitor m_test4 = {"HP", 4};
    cout<<endl;
    Monitor m_test5 = m_test4;
    cout<<endl;
#else
    Monitor m_test1;
    Monitor m_test2 = {"Asus"};
    Monitor m_test3 = {5};
    Monitor m_test4 = {"HP", 4};
    Monitor m_test5 = m_test4;
#endif

    cout<<"Creating dynamic object "<<endl;
    Monitor* p_monitor;
    p_monitor = new Monitor("Dynamic", 1);
    cout<<endl;
    cout<<"Deleting dynamic object "<<endl;
    delete p_monitor;
    cout<<endl;


    cout<<"Testing == operator"<<endl;
    cout<<(m_test4 == m_test3 ? "m_test4 == m_test3" : "m_test4 != m_test3")<<endl;
    cout<<(m_test4 == m_test5 ? "m_test4 == m_test5" : "m_test4 != m_test5")<<endl;
    cout<<endl;

    cout<<"Testing = operator: m_test3 = m_test4"<<endl;
    m_test3 = m_test4;
    cout<<"After m_test3 = m_test4: "<<(m_test4 == m_test3 ? "m_test4 == m_test3" : "m_test4 != m_test3")<<endl;
    cout<<endl;

    cout<<"Testing both ! and (string) operators"<<endl;
    cout<<"Before !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After another !m_test4: "<<(string)m_test4<<endl;
    cout<<endl;

    cout<<"Testing << operator"<<endl;
    cout<<"Calling cout<<m_test4: "<<endl;
    cout<<m_test4;

    cout<<endl;



    cout<<"Testing [] operator"<<endl<<endl;

    cout<<"Names of apps in m_test3, before changing app names in m_test4 and assigning m_test4 to m_test3:"<<endl;
    for(unsigned int i = 0; i < m_test3.get_number_of_apps(); i++)
    {
        cout<<"["<<i<<"]: "<<m_test3[i]->get_name()<<endl;
    }

    m_test4.get_apps()[0].set_name("pierwsza");
    m_test4.get_apps()[1].set_name("druga");
    m_test4.get_apps()[2].set_name("trzecia");

    cout<<"\nCalling m_test3 = m_test4 "<<endl;
    m_test3 = m_test4;

    cout<<"\nNames of apps in m_test3, after changing app names in m_test4 and assigning m_test4 to m_test3:"<<endl;
    for(unsigned int i = 0; i < m_test3.get_number_of_apps(); i++)
    {
        cout<<"["<<i<<"]: "<<m_test3[i]->get_name()<<endl;
    }
    cout<<endl;

    return 0;
}
