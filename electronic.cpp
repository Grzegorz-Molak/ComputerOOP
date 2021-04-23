#include "electronic.h"
#include <fstream>
#include <typeinfo>

int Electronic::m_quantity = 0;

Electronic::Electronic()
{
    this->m_quantity++;
#ifdef _DEBUG
    cout<<"Electronic(), 'Electronic' objects: "<<m_quantity<<endl;
#endif
}

Electronic::~Electronic()
{
    this->m_quantity--;
#ifdef _DEBUG
    cout<<"~Electronic(), 'Electronic' objects: "<<m_quantity<<endl;
#endif
}

ostream & operator<<( ostream &s , const Electronic& electronic)
{
s<<"Nazwa: "<<electronic.m_name<<endl;
s<<"ON/OFF: "<<electronic.m_power<<endl;
s<<"Uzytkownik: "<<electronic.m_user<<endl;
return s;
}
istream & operator>>( istream &s , Electronic& electronic)
{
    string title;
    s>>title>>electronic.m_name;
    s>>title>>electronic.m_power;
    s>>title>>electronic.m_user;
    return s;
}

bool Electronic::askToTurnOn()
{
    cout<<"Aby wykonywac te operacje urzadzenie musi byc wlaczone\n"
          <<"czy chcesz je wlaczyc? \n 1 - TAK, 0 - Nie"<<endl;
    bool open;
    cin>>open;
    if(!open)
    {
        cout<<"Aby wykonywac te operacje urzadzenie musi byc wlaczone"<<endl;
    }
    return open;

}

bool Electronic::power() const
{
    return m_power;
}

string Electronic::name() const
{
    return m_name;
}

void Electronic::setName(const string &name)
{
    m_name = name;
}

User Electronic::user() const
{
    return m_user;
}

void Electronic::setUser(const User &user)
{
    m_user = user;
}

