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
    // funkcje sterujace zawartoscia ******

private:
    static int m_quantity;
    string m_name = "anonim";
    unsigned int m_age = 0;
};


