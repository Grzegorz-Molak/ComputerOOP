#include <iostream>
#include "monitor.h"

using namespace std;

Monitor m_global = {"GLOBAL", 6};
App a_global = {"CS-GO"};
User u_global = {"Globalek", 11};

int test_objects()
{
#ifdef _DEBUG
    cout<<"\nTesting objects"<<endl;
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
    if(!p_monitor || !p_app || !p_user)
    {
        cout<<"Error with dynamic objects"<<endl;
        return 1;
    }

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

    if(!p_monitor || !p_app || !p_user)
    {
        cout<<"Error with dynamic objects"<<endl;
        return 1;
    }


    delete p_monitor;
    delete p_app;
    delete p_user;
#endif
    return 0;
}

int test_operators()
{
    cout<<"\n\n Testing operators:"<<endl;

    Monitor m_test1;
    cout<<endl;
    Monitor m_test2 = {"Operatorek"};
    cout<<endl;
    Monitor m_test3 = {"Operatorek", 4};
    cout<<endl;

    cout<<"Testing == operator:"<<endl;
    cout<<"Calling m_test3 == m_test1"<<endl;
    cout<<(m_test3 == m_test1)<<endl;
    cout<<"Calling m_test3 == m_test2"<<endl;
    cout<<(m_test3 == m_test2)<<endl;
    cout<<endl;

    cout<<"Testing = operator (m_test1 = m_test2) and (string) operator:"<<endl;
    cout<<"m_test1: "<<(string)m_test1<<endl;
    cout<<"m_test2: "<<(string)m_test2<<endl;
    cout<<"Calling m_test1 = m_test2"<<endl;
    m_test1 = m_test2;
    cout<<"After m_test1 = m_test2"<<endl;
    cout<<"m_test1: "<<(string)m_test1<<endl;
    cout<<"m_test2: "<<(string)m_test2<<endl;

    cout<<"\nTesting both ! and (string) operators:"<<endl;
    cout<<"Before !m_test3: "<<(string)m_test3<<endl;
    !m_test3;
    cout<<"After !m_test3: "<<(string)m_test3<<endl;
    !m_test3;
    cout<<"After another !m_test3: "<<(string)m_test3<<endl;
    cout<<endl;

    cout<<"Testing << operator:"<<endl;
    cout<<"Calling cout<<m_test3: "<<endl;
    cout<<m_test3;

    cout<<endl;



    cout<<"Testing [] operator:"<<endl;

    cout<<"Names of apps in m_test3, before assigning new values"<<endl;
    cout<<m_test3;

    cout<<"Changing manually values of 3 of m_test3 apps names using [] operator"<<endl;
    m_test3.get_apps()[0].set_name("pierwsza");
    m_test3.get_apps()[1].set_name("druga");
    m_test3.get_apps()[2].set_name("trzecia");

    cout<<"\nNames of apps in m_test3 after assigning new values"<<endl;
    cout<<m_test3;

    cout<<endl;

    return 0;
}



