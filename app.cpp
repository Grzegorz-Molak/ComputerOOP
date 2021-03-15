#include "app.h"

unsigned int App::quantity = 0;

App::App()
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(), current number of class 'App' objects: "<<quantity<<endl;
#endif  
}

App::App(string name_of_app)
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(string name_of_app), current number of class 'App' objects: "<<quantity<<endl;
#endif

    this->name = name_of_app;
}

App::App(const App &app_to_copy)
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(const App &app_to_copy), current number of class 'App' objects: "<<quantity<<endl;
#endif

    this->name = app_to_copy.name;
}

App::~App()
{
    quantity--;
#ifdef _DEBUG
    cout<<"~App(), current number of class 'App' objects: "<<quantity<<endl;
#endif   
}

int App::get_quantity()
{
    return quantity;
}
