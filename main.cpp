#include <iostream>
#include "monitor.h"
using namespace std;

int main()
{
    Monitor test;
    Monitor test2("LCD");
    Monitor test3(4);
    Monitor test4("LPG", 2);
    Monitor test5(test3);
    return 0;
}
