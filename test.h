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

    cout<<"Displaying global objects"<<endl;
    cout<<"m_global:\n"<<m_global;
    cout<<"a_global:\n"<<a_global.get_name()<<endl;
    cout<<"u_global:\n"<<u_global.get_name()<<" "<<u_global.get_age()<<endl;

    cout<<"\nCreating five test monitors:"<<endl;

    cout<<"m_test1: without any values in initialization "<<endl;
    Monitor m_test1;
    cout<<m_test1<<endl;

    cout<<"m_test2: with initialized model name"<<endl;
    Monitor m_test2 = {"Asus"};
    cout<<m_test2<<endl;

    cout<<"m_test3: with initialized number of apps"<<endl;
    Monitor m_test3 = {5};
    cout<<m_test3<<endl;

    cout<<"m_test4: with initialized model name and number of apps "<<endl;
    Monitor m_test4 = {"HP", 4};
    cout<<m_test4<<endl;

    cout<<"m_test5: a copy of m_test4 "<<endl;
    Monitor m_test5 = m_test4;
    cout<<m_test5<<endl;

    cout<<"Changing names of m_global apps to make sure they are also copied correctly"<<endl;
    m_global[0]->set_name("Fizyka");
    m_global[1]->set_name("Matematyka");
    m_global[2]->set_name("Chemia");
    cout<<"m_global:\n"<<m_global;

    cout<<"m_test6: a copy of m_global "<<endl;
    Monitor m_test6 = m_global;
    cout<<m_test6<<endl;

    cout<<"Testing if m_test6 apps didnt copy adresses of m_global apps but only values by changing one app name in m_test6: "<<endl;
    m_test6[0]->set_name("Biologia");
    cout<<"m_global:\n"<<m_global<<"m_test6:\n"<<m_test6<<endl;

    cout<<"Creating dynamic objects(Monitor, App and User):"<<endl;

    Monitor* p_monitor;
    cout<<"p_monitor: "<<endl;
    p_monitor = new Monitor("Dynamic", 1);
    cout<<*p_monitor<<endl;

    App* p_app;
    cout<<"p_app: "<<endl;
    p_app = new App("Dynamo");
    cout<<p_app->get_name()<<endl<<endl;

    User* p_user;
    cout<<"p_user: "<<endl;
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

    cout<<"m_test1: without any values in initialization "<<endl;
    Monitor m_test1;
    cout<<m_test1<<endl;

    cout<<"m_test2: with initialized model name"<<endl;
    Monitor m_test2 = {"Operatorek"};
    cout<<m_test2<<endl;

    cout<<"m_test3: with initialized model name and number of apps"<<endl;
    Monitor m_test3 = {"Operatorek", 4};
    cout<<m_test3<<endl;

    cout<<"Testing == operator(two monitors are equal if their model names are same):"<<endl;
    cout<<"Calling m_test3 == m_test1:"<<endl;
    cout<<(m_test3 == m_test1)<<endl;
    cout<<"Calling m_test3 == m_test2:"<<endl;
    cout<<(m_test3 == m_test2)<<endl;
    cout<<endl;

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
    cout<<"Calling m_test1 = m_test2"<<endl;
    m_test1 = m_test3;
    cout<<"After m_test1 = m_test3"<<endl;
    cout<<"m_test1:\n"<<m_test1;
    cout<<"m_test3:\n"<<m_test3<<endl;


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


    cout<<endl;

    return 0;
}



