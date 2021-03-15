#pragma once
#include <iostream>

using namespace std;

class App
{
public:
    App();
    App(string name_of_app);
    App(const App &app_to_copy);
   ~App();

    static int get_quantity();

private:
    static unsigned int quantity;
    string name = "unknown";
};

