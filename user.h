#pragma once
#include <iostream>

using namespace std;

class User
{
public:
    // KONSTRUKTORY **********
    User();
    User(string name_of_user);
    User(int age_of_user);
    User(string name_of_user, int age_of_user);
    User(const User &user_to_copy);
    // KONSTRUKTORY **********
   ~User(); // DESTRUKTOR **********

    static int get_quantity() {return m_quantity;}

    User& operator=(const User &user_to_copy); // przeciazony operator przypisania

    // funkcje sterujace zawartoscia ******
    string name(){return m_name;}
    int age(){return m_age;}
    void setName(string name) {m_name = name;}
    void setAge(unsigned int age) { m_age = age;}
    // funkcje sterujace zawartoscia ******

    friend ostream & operator<<( ostream &s , const User& user);
    friend istream & operator>>( istream &s , User& user);
private:
    static int m_quantity;
    string m_name = "anonim";
    unsigned int m_age = 18;
};


