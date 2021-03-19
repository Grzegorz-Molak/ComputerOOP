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

    static int get_quantity() {return quantity;}

    User& operator=(const User &user_to_copy); // przeciazony operator przypisania

    // funkcje sterujace zawartoscia ******
    string get_name(){return name;}
    int get_age(){return age;}
    // funkcje sterujace zawartoscia ******

private:
    static unsigned int quantity;
    string name = "anonim";
    unsigned int age = 0;
};


