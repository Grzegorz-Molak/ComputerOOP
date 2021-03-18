#include "user.h"

unsigned int User::quantity = 0;

User::User() // podstawowy konstruktor
{
    quantity++;
#ifdef _DEBUG
    cout<<"User(), current number of class 'User' objects: "<<quantity<<endl;
#endif
}

User::User(string name_of_user) // z zainicjalizowana nazwa uzytkownika
{
    quantity++;
#ifdef _DEBUG
    cout<<"User(string name_of_user), current number of class 'User' objects: "<<quantity<<endl;
#endif
    this->name = name_of_user;
}

User::User(int age_of_user) // z inicjalizacja wieku uzytkownika
{
    quantity++;
#ifdef _DEBUG
    cout<<"User(int age_of_user), current number of class 'User' objects: "<<quantity<<endl;
#endif
    this->age = age_of_user;
}

User::User(string name_of_user, int age_of_user) // ze wszelka inicjalizacja
{
    quantity++;
#ifdef _DEBUG
    cout<<"User(string name_of_user, int age_of_user), current number of class 'User' objects: "<<quantity<<endl;
#endif
    this->name = name_of_user;
    this->age = age_of_user;
}

User::User(const User &user_to_copy) // konstruktor kopiujacy
{
    quantity++;
#ifdef _DEBUG
    cout<<"User(const User &user_to_copy), current number of class 'User' objects: "<<quantity<<endl;
#endif

    this->name = user_to_copy.name;
    this->age = user_to_copy.age;
}

User::~User() // destruktor
{
    quantity--;
#ifdef _DEBUG
    cout<<"~User(), current number of class 'User' objects: "<<quantity<<endl;
#endif
}

User& User::operator=(const User &user_to_copy) // operator przypisujacy uzytkownikowi parametry innego uzytkownika
{
    name = user_to_copy.name;
    age = user_to_copy.age;
    return *this;
}


