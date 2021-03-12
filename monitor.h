#pragma once
#include "model.h"
#include "user.h"

class Monitor
{
public:
    Monitor();
private:
    Model model;
    int number_of_users;
    User* users;
};


