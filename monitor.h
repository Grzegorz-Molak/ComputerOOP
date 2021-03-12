#pragma once
#include "user.h"

using namespace std;

class Monitor
{
public:
    Monitor();
    Monitor(string model_name);
    Monitor(unsigned int users_number);
    Monitor(string model_name, unsigned int users_number);
    Monitor(const Monitor &monitor_to_copy);
    ~Monitor();

    int get_number_of_users();
private:
    string name_of_model = "unknown";
    unsigned int number_of_users = 0;
    User* users = 0;
};


