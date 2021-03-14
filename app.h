#pragma once
#include <iostream>

using namespace std;

class App
{
public:
    App();
   ~App();
    void change_quantity(int change);
private:
    static unsigned int quantity;
    string name;
};

