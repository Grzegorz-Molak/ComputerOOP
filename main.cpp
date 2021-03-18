#include <iostream>
#include "monitor.h"
using namespace std;

int test();

int main()
{
#ifdef _DEBUG
    test();
#endif
    return 0;
}
