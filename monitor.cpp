#include "monitor.h"

unsigned int Monitor::quantity = 0;

Monitor::Monitor()
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"Monitor(), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif
}
Monitor::Monitor(string model_name)
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"Monitor(string model_name), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = model_name;
}
Monitor::Monitor(unsigned int apps_number)
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"Monitor(unsigned int apps_number), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->number_of_apps= apps_number;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps];
    }
}
Monitor::Monitor(string model_name, unsigned int apps_number)
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"Monitor(string model_name, unsigned int apps_number), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = model_name;
    this->number_of_apps = apps_number;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps];
    }

}

Monitor::Monitor(const Monitor &monitor_to_copy)
{
    change_quantity(1);
#ifdef _DEBUG
    cout<<"Monitor(const Monitor &monitor_to_copy), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    this->name_of_model = monitor_to_copy.name_of_model;
    this->number_of_apps = monitor_to_copy.number_of_apps;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps];
    }
}


Monitor::~Monitor()
{
    change_quantity(-1);
#ifdef _DEBUG
    cout<<"~Monitor(), current number of class 'Monitor' objects: "<<quantity<<endl;
#endif

    if(this->opened_apps)
    {
        delete[] this->opened_apps;
    }
}

void Monitor::change_quantity(int change)
{
   quantity += change;
}

int Monitor::get_number_of_users()
{
    return this->number_of_apps;
}
