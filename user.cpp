#include "user.h"

int User::m_quantity = 0;

// KONSTRUKTORY ****************************************

User::User() // podstawowy konstruktor
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"User(), 'User' objects: "<<m_quantity<<endl;
#endif
}

User::User(string name_of_user) // z zainicjalizowana nazwa uzytkownika
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"User("<<name_of_user<<"), 'User' objects: "<<m_quantity<<endl;
#endif
    m_name = name_of_user;
}

User::User(int age_of_user) // z inicjalizacja wieku uzytkownika
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"User("<<age_of_user<<"), 'User' objects: "<<m_quantity<<endl;
#endif
    m_age = age_of_user;
}

User::User(string name_of_user, int age_of_user) // ze wszelka inicjalizacja
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"User("<<name_of_user<<" "<<age_of_user<<"), 'User' objects: "<<m_quantity<<endl;
#endif
    m_name = name_of_user;
    m_age = age_of_user;
}

User::User(const User &user_to_copy) // konstruktor kopiujacy
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"User(const User &user_to_copy),  'User' objects: "<<m_quantity<<endl;
#endif

    m_name = user_to_copy.m_name;
    m_age = user_to_copy.m_age;
}

// KONSTRUKTORY ****************************************

User::~User() // destruktor
{
    m_quantity--;
#ifdef _DEBUG
       cout<<"~User(), 'User' objects: "<<m_quantity<<endl;
#endif
}

// OPERATORY *****************************

User& User::operator=(const User &user_to_copy) // operator przypisujacy uzytkownikowi parametry innego uzytkownika
{
    m_name = user_to_copy.m_name;
    m_age = user_to_copy.m_age;
    return *this;
}

ostream & operator<<( ostream &s , const User& user)
{
return s << user.m_name << " | " << user.m_age;
}
istream & operator>>( istream &s , User& user)
{
return s >> user.m_name >> user.m_age;
}

// OPERATORY *****************************



