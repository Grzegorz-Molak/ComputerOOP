#include "monitor.h"


Monitor::Monitor()
{
    #ifdef _DEBUG
        cout<<"Monitor()"<<endl;
    #endif
}
Monitor::Monitor(string model_name)
{
    #ifdef _DEBUG
        cout<<"Monitor(string model_name)"<<endl;
    #endif

    this->name_of_model = model_name;
}
Monitor::Monitor(unsigned int apps_number)
{
    #ifdef _DEBUG
        cout<<"Monitor(unsigned int apps_number)"<<endl;
    #endif

    this->number_of_apps= apps_number;
    if(this->number_of_apps > 0)
    {
        this->opened_apps = new App[this->number_of_apps];
    }
}
Monitor::Monitor(string model_name, unsigned int apps_number)
{
    #ifdef _DEBUG
        cout<<"Monitor(string model_name, unsigned int apps_number)"<<endl;
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
    #ifdef _DEBUG
        cout<<"Monitor(const Monitor &monitor_to_copy)"<<endl;
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
    #ifdef _DEBUG
        cout<<"~Monitor()"<<endl;
    #endif
    if(this->opened_apps)
    {
        delete[] this->opened_apps;
    }
}

int Monitor::get_number_of_users()
{
    return this->number_of_apps;
}
