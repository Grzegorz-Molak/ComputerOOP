#include "user.h"

User::User()
{
    #ifdef _DEBUG
        cout<<"User()"<<endl;
    #endif
}

User::~User()
{
    #ifdef _DEBUG
        cout<<"~User()"<<endl;
    #endif
}
