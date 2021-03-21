#include <iostream>
#include "monitor.h"
#include "test.cpp"
using namespace std;


int main()
{
if(test_objects() == 0)
{
    cout<<"Finished testing objects"<<endl;
}
#ifdef _DEBUG
    if(test_operators() == 0)
    {
        cout<<"Finished testing operators"<<endl;
    }
#endif
    return 0;
}
