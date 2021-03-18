#include <iostream>
#include "monitor.h"
#define new_line cout<<endl;
using namespace std;

int main()
{
    Monitor m_test1;
    new_line
    Monitor m_test2 = {"Asus"};
    new_line
    Monitor m_test3 = {5};
    new_line
    Monitor m_test4 = {"HP", 4};
    new_line
    Monitor m_test5 = m_test4;
    new_line

    cout<<"Testing == operator"<<endl;
    cout<<(m_test4 == m_test3 ? "m_test4 == m_test3" : "m_test4 != m_test3")<<endl;
    cout<<(m_test4 == m_test5 ? "m_test4 == m_test5" : "m_test4 != m_test5")<<endl;
    new_line

    cout<<"Testing = operator: m_test3 = m_test4"<<endl;
    m_test3 = m_test4;
    cout<<"After m_test3 = m_test4: "<<(m_test4 == m_test3 ? "m_test4 == m_test3" : "m_test4 != m_test3")<<endl;
    new_line

    cout<<"Testing both ! and (string) operators"<<endl;
    cout<<"Before !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After !m_test4: "<<(string)m_test4<<endl;
    !m_test4;
    cout<<"After another !m_test4: "<<(string)m_test4<<endl;
    new_line

    cout<<"Testing << operator"<<endl;
    cout<<"Calling cout<<m_test4: "<<endl;
    cout<<m_test4;

    new_line;



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
    new_line

    return 0;
}
