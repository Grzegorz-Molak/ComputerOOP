
#include <iostream>

using namespace std;

int getInt()
{
    int number;
    while (true)
    {
        if (cin>>number)
        {
                return number;
        }
        else
        {
            string text;

            cin.clear();
            getline(cin, text);
            cout<<text<<" nie jest liczba. Sproboj jeszcze raz"<<endl;
        }
    }
}

int getInt(int min, int max)
{
    int number;
    while(true)
    {
        number = getInt();
        if(number >= min && number <= max)
        {
            return number;
        }
        else
        {
            cout<<"Prosze podac liczbe z przedzialu <"<<min<<","<<max<<">"<<endl;
        }
    }


}
