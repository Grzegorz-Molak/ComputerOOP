#include "electronic.h"
#include <fstream>
#include "useful.h"


int Electronic::m_quantity = 0;


// KONSTRUKTORY I DESTRUKTORY ***********************
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
// KONSTRUKTORY I DESTRUKTORY ***********************

// OPERATORY ****************************************
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

// OPERATORY ****************************************
// INNE FUNKCJE *************************************
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

void Electronic::edit()
{
    cout<<"Edycja pola on/off nie jest mozliwa"<<endl;
    string text;
    cout<<"Nowa nazwa urzadzenia: "<<endl;
        cin>>text;
        m_name = text;
    cout<<"Nowa nazwa uzytkownika: "<<endl;
        cin>>text;
        m_user.setName(text);
    cout<<"Nowy wiek uzytkownika: "<<endl;
        m_user.setAge(getInt());


}

int Electronic::functions()
{
cout<<"1. Wlacz/Wylacz, aktualnie urzadzenie jest"<<(m_power ?  "ON" : "OFF")<<endl;
return 0;
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

// INNE FUNKCJE *************************************

