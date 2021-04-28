#pragma once
#include <iostream>
#include <vector>

#include "useful.h"

#include "electronic.h"
#include "monitor.h"
#include "computermonitor.h"
#include "hairdryer.h"

using namespace std;
vector<Electronic*> electronics;

void interface();
int menu();
int chooseObject();
void showObjectsList();

void newObject();
void deleteObject();
void deleteAllObjects();
void save();
void read();
void edit();
void print();

int menu()
{
    cout<<"Obiekty: "<<endl;
    showObjectsList();
    cout<<"\nWybierz dzialanie: "<<endl;
    cout<<"1 - Utworz nowy obiekt"<<endl;
    cout<<"2 - Edytuj istniejacy obiekt"<<endl;
    cout<<"3 - Usun istniejacy obiekt"<<endl;
    cout<<"4 - Przetestuj inne funkcje obiektow"<<endl;
    cout<<"5 - Zapisz obiekt do pliku"<<endl;
    cout<<"6 - Wczytaj obiekt z pliku"<<endl;
    cout<<"7 - Wyswietl obiekt"<<endl;
    cout<<"0 - By opuscic program"<<endl;

    return getInt(0,7);

}

void interface()
{
    bool end = false;
    electronics.emplace_back(new ComputerMonitor("Comp"));
    electronics.emplace_back(new Monitor("Monit"));
    electronics[0]->switchPower();
    //electronics[0]->print(); // Wyświetla dla ComputerMonitor
    //electronics[1]->print(); // Wyświetla dla Monitor

    while(!end)
    {
        switch(menu())
        {
            case 0:
                deleteAllObjects();
                end = true;
                break;
            case 1:
                newObject();
                break;
            case 2:
                edit();
                break;
            case 3:
                deleteObject();
                break;
            case 4:
                cout<<"4"<<endl;
                break;
            case 5:
                save();
                break;
            case 6:
                read();
                break;
            case 7:
                print();
                break;

            default:
                cout<<"Nie podano wartosci z przedzialu 0-6"<<endl;
        }
    }
}


void showObjectsList()
{
    for(auto i = electronics.begin(); i < electronics.end(); i++  )
    {
        cout<<(i - electronics.begin())<<". "<<(*i)->name()<<endl;
    }
}

int chooseObject()
{
    showObjectsList();

    cout<<"Wybierz obiekt podajac jego indeks(po lewej stronie)"<<endl;
    return getInt(0, static_cast<int>(electronics.size())-1);
}

void newObject()
{
    string name;
    cout<<"Jaka ma byc nazwa nowego obiektu? "<<endl;
    cin>>name;
    cout<<"Czym jest "<<name<<"? Prosze wybrac 1,2 albo 3"<<endl;
    cout<<"1: Suszarka"<<endl;
    cout<<"2: Monitor"<<endl;
    cout<<"3: Monitor komputerowy"<<endl;
    switch(getInt(1,3))
    {
        case 1:
            electronics.emplace_back(new Hairdryer(name));
            break;
        case 2:
            electronics.emplace_back(new Monitor(name));
            break;
        case 3:
            electronics.emplace_back(new ComputerMonitor(name));
            break;
    }
}

void deleteObject()
{
    int deleting = getInt(0, electronics.size());
    delete electronics[deleting];
    electronics.erase(electronics.begin()+deleting);
}
void deleteAllObjects()
{
    for(auto i = electronics.begin(); i < electronics.end(); i++ )
    {
        delete *i;
        electronics.erase(i);
    }
}

void edit()
{
electronics[chooseObject()]->edit();
}

void save()
{
electronics[chooseObject()]->save();
}


void read()
{
electronics[chooseObject()]->read();
}

void print()
{
electronics[chooseObject()]->print();
}



