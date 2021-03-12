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
Monitor::Monitor(unsigned int users_number)
{
    #ifdef _DEBUG
        cout<<"Monitor(int users_number)"<<endl;
    #endif

    this->number_of_users= users_number;
    if(this->number_of_users > 0)
    {
        this->users = new User[number_of_users];
    }
}
Monitor::Monitor(string model_name, unsigned int users_number)
{
    #ifdef _DEBUG
        cout<<"Monitor(string model_name, int users_number)"<<endl;
    #endif

    this->name_of_model = model_name;
    this->number_of_users = users_number;
    if(this->number_of_users > 0)
    {
        this->users = new User[number_of_users];
    }

}

Monitor::Monitor(const Monitor &monitor_to_copy)
{
    #ifdef _DEBUG
        cout<<"Monitor(const Monitor &monitor_to_copy)"<<endl;
    #endif
    this->name_of_model = monitor_to_copy.name_of_model;
    this->number_of_users = monitor_to_copy.number_of_users;
    if(this->number_of_users > 0)
    {
        this->users = new User[this->number_of_users];
    }
}


Monitor::~Monitor()
{
    #ifdef _DEBUG
        cout<<"~Monitor()"<<endl;
    #endif
    if(this->users)
    {
        delete[] this->users;
    }
}

int Monitor::get_number_of_users()
{
    return this->number_of_users;
}
