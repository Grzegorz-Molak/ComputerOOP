#include "app.h"

unsigned int App::quantity = 0;

App::App()
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"App(), current number of class 'App' objects: "<<quantity<<endl;
#endif  
}
App::~App()
{
    change_quantity(-1);
#ifdef _DEBUG
    cout<<"~App(), current number of class 'App' objects: "<<quantity<<endl;
#endif   
}

void App::change_quantity(int change)
{
   quantity += change;
}


