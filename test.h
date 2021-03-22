#pragma once

#include <iostream>
#include "monitor.h"

using namespace std;

Monitor m_global = {"GLOBAL", 6};
App a_global = {"CS-GO"};
User u_global = {"Globalek", 11};

int test_objects()
{
    cout<<"\nTesting objects"<<endl;
    cout<<"\nCreating five test monitors:"<<endl;
    Monitor m_test1;
    cout<<m_test1<<endl;
    Monitor m_test2 = {"Asus"};
    cout<<m_test2<<endl;
    Monitor m_test3 = {5};
    cout<<m_test3<<endl;
    Monitor m_test4 = {"HP", 4};
    cout<<m_test4<<endl;
    Monitor m_test5 = m_test4;
    cout<<m_test5<<endl;

    cout<<"Creating dynamic objects(Monitor, App and User):"<<endl;
    Monitor* p_monitor;
    p_monitor = new Monitor("Dynamic", 1);
    cout<<*p_monitor<<endl;
    App* p_app;
    p_app = new App("Dynamo");
    cout<<p_app->get_name()<<endl<<endl;
    User* p_user;
    p_user = new User("Dynamek");
    cout<<p_user->get_name()<<" "<<p_user->get_age()<<endl<<endl;
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
    return 0;
}

int test_operators()
{
    cout<<"\n\n Testing operators:"<<endl;
    cout<<"Creating 3 monitors to test"<<endl;

    Monitor m_test1;
    cout<<m_test1<<endl;
    Monitor m_test2 = {"Operatorek"};
    cout<<m_test2<<endl;
    Monitor m_test3 = {"Operatorek", 4};
    cout<<m_test3<<endl;

    cout<<"Testing == operator:"<<endl;
    cout<<"Calling m_test3 == m_test1"<<endl;
    cout<<(m_test3 == m_test1)<<endl;
    cout<<"Calling m_test3 == m_test2"<<endl;
    cout<<(m_test3 == m_test2)<<endl;
    cout<<endl;

<<<<<<< HEAD
    cout<<"Testing [] operator:"<<endl;
    cout<<"m_test3, before assigning new values:"<<endl;
    cout<<m_test3;

    cout<<"Changing manually values of 3 of m_test3 apps names using [] operator:"<<endl;
    m_test3.get_apps()[0].set_name("pierwsza");
    m_test3.get_apps()[1].set_name("druga");
    m_test3.get_apps()[2].set_name("trzecia");

    cout<<"m_test3 after assigning new values:"<<endl;
    cout<<m_test3<<endl;

    cout<<"Testing = operator (before m_test1 = m_test3):"<<endl;
    cout<<"m_test1:\n"<<m_test1;
    cout<<"m_test3:\n"<<m_test3<<endl;
=======
    cout<<"Testing = operator (m_test1 = m_test3) and (string) operator:"<<endl;
    cout<<"m_test1: "<<(string)m_test1<<endl;
    cout<<"m_test3: "<<(string)m_test3<<endl;
>>>>>>> 68f8b2cfc0aa0027d2fb322531b310da5ded70aa
    cout<<"Calling m_test1 = m_test2"<<endl;
    m_test1 = m_test3;
    cout<<"After m_test1 = m_test3"<<endl;
    cout<<"m_test1: "<<(string)m_test1<<endl;
    cout<<"m_test3: "<<(string)m_test3<<endl;

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

    cout<<"Names of apps in m_test3 after assigning new values"<<endl;
    cout<<m_test3;

    cout<<endl;

    return 0;
}



