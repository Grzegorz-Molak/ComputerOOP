#include <iostream>
#include "monitor.h"

using namespace std;

Monitor m_global = {"GLOBAL", 6};
App a_global = {"CS-GO"};
User u_global = {"Globalek", 11};

int test()
{
#ifdef _DEBUG
    cout<<"\nCreating five test monitors:"<<endl;
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

    cout<<"Creating dynamic objects(Monitor, App and User):"<<endl;
    Monitor* p_monitor;
    p_monitor = new Monitor("Dynamic", 1);
    cout<<endl;
    App* p_app;
    p_app = new App("Dynamo");
    cout<<endl;
    User* p_user;
    p_user = new User("Dynamek");
    cout<<endl;

    cout<<"Deleting dynamic objects:"<<endl;
    delete p_monitor;
    cout<<endl;
    delete p_app;
    cout<<endl;
    delete p_user;
    cout<<endl;
#else
    Monitor m_test1;
    Monitor m_test2 = {"Asus"};
    Monitor m_test3 = {5};
    Monitor m_test4 = {"HP", 4};
    Monitor m_test5 = m_test4;

    Monitor* p_monitor;
    p_monitor = new Monitor("Dynamic", 1);
    App* p_app;
    p_app = new App("Dynamo");
    User* p_user;
    p_user = new User("Dynamek");

    delete p_monitor;
    delete p_app;
    delete p_user;
#endif



    cout<<"Testing == operator:"<<endl;
    cout<<"Calling m_test4 == m_test3"<<endl;
    cout<<(m_test4 == m_test3)<<endl;
    cout<<"Calling m_test4 == m_test5"<<endl;
    cout<<(m_test4 == m_test5)<<endl;
    cout<<endl;

    cout<<"Testing = operator (m_test3 = m_test4) and (string) operator:"<<endl;
    cout<<"m_test3: "<<(string)m_test3<<endl;
    cout<<"m_test4: "<<(string)m_test4<<endl;
    cout<<"Calling m_test3 = m_test4"<<endl;
    m_test3 = m_test4;
    cout<<"After m_test3 = m_test4"<<endl;
    cout<<"m_test3: "<<(string)m_test3<<endl;
    cout<<"m_test4: "<<(string)m_test4<<endl;

    cout<<"\nTesting both ! and (string) operators:"<<endl;
    cout<<"Before !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After another !m_test4: "<<(string)m_test4<<endl;
    cout<<endl;

    cout<<"Testing << operator:"<<endl;
    cout<<"Calling cout<<m_test4: "<<endl;
    cout<<m_test4;

    cout<<endl;



    cout<<"Testing [] operator:"<<endl;

    cout<<"Names of apps in m_test4, before assigning new values"<<endl;
    for(unsigned int i = 0; i < m_test4.get_number_of_apps(); i++)
    {
        cout<<"["<<i<<"]: "<<m_test4[i]->get_name()<<endl;
    }

    cout<<"Changing values of m_test4 apps names"<<endl;
    m_test4.get_apps()[0].set_name("pierwsza");
    m_test4.get_apps()[1].set_name("druga");
    m_test4.get_apps()[2].set_name("trzecia");

    cout<<"\nNames of apps in m_test4 after assigning new values"<<endl;
    for(unsigned int i = 0; i < m_test4.get_number_of_apps(); i++)
    {
        cout<<"["<<i<<"]: "<<m_test4[i]->get_name()<<endl;
    }
    cout<<endl;

    return 0;
}
