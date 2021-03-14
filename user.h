#pragma once
#include <iostream>

using namespace std;

class User
{
public:
    User();
   ~User();
    void change_quantity(int change);
private:
    static unsigned int quantity;
    string name;
    int age;
};


