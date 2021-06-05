#include <iostream>
#include "containerinterface.h"
using namespace std;


int main()
{

Container<int> c;
cout<<"Testowanie kontenera dla typow int i string"<<endl;
cout<<"Dodawanie 3 elementow: 1, 2, 3"<<endl;
c.push_back(1);
c.push_back(2);
c.push_back(3);
cout<<c<<endl;
cout<<"Dodawanie elementu 4 na drugie miejsce w kontenerze"<<endl;
c.push(2,4);
cout<<c<<endl;
cout<<"Przenosze 2. element na koniec"<<endl;
c.moveToEnd(2);
cout<<c<<endl;
cout<<"Zamieniam miejscami 1. i 3. element"<<endl;
c.swap(1,3);
cout<<c<<endl;
cout<<"Usuwam 2. element"<<endl;
c.pop(2);
cout<<c<<endl;
cout<<"Uzyskuje dostep do 2. elementu"<<endl;
cout<<c[2]<<endl;

cout<<"Kopiuje kontener"<<endl;
Container<int> c2 = c;
cout<<(c == c2)<<endl;
cout<<"Dodaje element do nowego kontenera i znowu sprawdzam zgodnosc"<<endl;
c2.push(1, 1);
cout<<"Pierwszy: \n"<<c<<"\nDrugi: \n"<<c2<<endl;
cout<<(c == c2)<<endl;

cout<<"Sprawdzam czy sprawdza tylko ilosc elementow czy tez zgodnosc na miejscach"<<endl;
c2.pop(1);
c2.swap(1,3);
cout<<"Pierwszy: \n"<<c<<"\nDrugi: \n"<<c2<<endl;
cout<<(c==c2)<<endl;


Container<string> s;
cout<<"Dodawanie 3 elementow: jeden, dwa, trzy"<<endl;
s.push_back("jeden");
s.push_back("dwa");
s.push_back("trzy");
cout<<s<<endl;
cout<<"Dodawanie elementu cztery na drugie miejsce w kontenerze"<<endl;
s.push(2, "cztery");
cout<<s<<endl;
cout<<"Przenosze 2. element na koniec"<<endl;
s.moveToEnd(2);
cout<<s<<endl;
cout<<"Zamieniam miejscami 1. i 3. element"<<endl;
s.swap(1,3);
cout<<s<<endl;
cout<<"Usuwam 2. element"<<endl;
s.pop(2);
cout<<s<<endl;
cout<<"Uzyskuje dostep do 2. elementu"<<endl;
cout<<s[2]<<endl;

cout<<"Kopiuje kontener"<<endl;
Container<string> s2 = s;
cout<<(s == s2)<<endl;
cout<<"Dodaje element do nowego kontenera i znowu sprawdzam zgodnosc"<<endl;
s2.push(1, "nowy");
cout<<"Pierwszy: \n"<<s<<"\nDrugi: \n"<<s2<<endl;
cout<<(s == s2)<<endl;

cout<<"Sprawdzam czy sprawdza tylko ilosc elementow czy tez zgodnosc na miejscach"<<endl;
s2.pop(1);
s2.swap(1,3);
cout<<"Pierwszy: \n"<<s<<"\nDrugi: \n"<<s2<<endl;
cout<<(s==s2)<<endl;

interface();
    return 0;
}
