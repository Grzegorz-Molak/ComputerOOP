#include "user.h"

unsigned int User::quantity = 0;

User::User()
{
change_quantity(1);
#ifdef _DEBUG
    cout<<"User(), current number of class 'User' objects: "<<quantity<<endl;
#endif
}

User::~User()
{
    change_quantity(-1);
#ifdef _DEBUG
    cout<<"~User(), current number of class 'User' objects: "<<quantity<<endl;
#endif
}

void User::change_quantity(int change)
{
   quantity += change;
}
