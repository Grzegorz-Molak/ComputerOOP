#pragma once
#include <iostream>

using namespace std;

class User
{
public:
    User();
    User(string name_of_user);
    User(int age_of_user);
    User(string name_of_user, int age_of_user);
    User(const User &user_to_copy);
   ~User();

    static int get_quantity() {return quantity;}

    User& operator=(const User &user_to_copy);

    string get_name(){return name;}
    int get_age(){return age;}

private:
    static unsigned int quantity;
    string name = "anonim";
    unsigned int age = 0;
};


