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
void newObjectRead();
void deleteObject();
void deleteObject(int i);
void deleteAllObjects();
void save();
void read();
void edit();
void print();
void functions();

int menu()
{
    showObjectsList();

    if(electronics.size() > 0)
    {
    cout<<"\nWybierz dzialanie: "<<endl;
    cout<<"******************************"<<endl;
    cout<<"1 - Utworz nowy obiekt"<<endl;
    cout<<"2 - Edytuj istniejacy obiekt"<<endl;
    cout<<"3 - Usun istniejacy obiekt"<<endl;
    cout<<"4 - Przetestuj inne funkcje obiektow"<<endl;
    cout<<"5 - Zapisz obiekt do pliku"<<endl;
    cout<<"6 - Wczytaj obiekt z pliku"<<endl;
    cout<<"7 - Wyswietl obiekt"<<endl;
    cout<<"0 - By opuscic program"<<endl;
    cout<<"******************************"<<endl;
    return getInt(0,7);
    }
    else
    {
        cout<<"\nWybierz dzialanie: "<<endl;
        cout<<"******************************"<<endl;
        cout<<"1 - Utworz nowy obiekt"<<endl;
        cout<<"2 - Wczytaj obiekt z pliku"<<endl;
        cout<<"0 - By opuscic program"<<endl;
        cout<<"******************************"<<endl;
        int index = getInt(0,2);
        if(index == 2) return 6;
        else return index;
    }



}

void interface()
{
    bool end = false;

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
                functions();
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
    cout<<"\nObiekty: "<<endl;
    if(electronics.size() == 0)
    {
        cout<<"Brak obiektow, moze chcesz utworzyc nowy?"<<endl;
    }
    else
    {
        for(auto i = electronics.begin(); i < electronics.end(); i++  )
        {
            cout<<(i - electronics.begin())<<". "<<(*i)->name()<<endl;
        }
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
    cout<<"Czy chcesz od razu wlaczyc obiekt? "<<endl;
    cout<<"1. TAK"<<endl;
    cout<<"2. NIE"<<endl;
    if(getInt(1,2) == 1)
        electronics[electronics.size()-1]->switchPower();
}

void newObjectRead()
{
    cout<<"Do obiektu jakiego typu chcesz wczytac plik?"<<endl;
    cout<<"1. Suszarka"<<endl;
    cout<<"2. Monitor"<<endl;
    cout<<"3. Monitor Komputerowy"<<endl;
    int type = getInt(1,3);
    if(type == 1)
        electronics.emplace_back(new Hairdryer("readfromfile"));
    else if(type == 2)
        electronics.emplace_back(new Monitor("readfromfile"));
    else
        electronics.emplace_back(new ComputerMonitor("readfromfile"));
}

void deleteObject()
{
    int i = chooseObject();
    deleteObject(i);
}
void deleteObject(int i)
{
    delete electronics[i];
    electronics.erase(electronics.begin()+i);
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

void functions()
{
   string name;
   int index = chooseObject();
   int type = electronics[index]->functions();
   if(type == 1)
   {
       if(getInt(1,2) == 1)
           electronics[index]->switchPower();
       else
           static_cast<Hairdryer*>(electronics[index])->setHeat_level();
   }
   else if(type == 2)
   {
       switch(getInt(1,3))
       {
           case 1:
                electronics[index]->switchPower();
                break;
           case 2:
                cout<<"Prosze podac nazwe aplikacji: "<<endl;
                cin>>name;
                static_cast<Monitor*>(electronics[index])->openApp(name);
                break;
           case 3:
                static_cast<Monitor*>(electronics[index])->closeApp();
                break;
       }
   }
   else
   {
       switch(getInt(1,4))
       {
           case 1:
                electronics[index]->switchPower();
                break;
           case 2:
                cout<<"Prosze podac nazwe aplikacji: "<<endl;
                cin>>name;
                static_cast<ComputerMonitor*>(electronics[index])->openApp(name);
                break;
           case 3:
                static_cast<Monitor*>(electronics[index])->closeApp();
                break;
           case 4:
                static_cast<ComputerMonitor*>(electronics[index])->setOutput();
                break;
       }
   }
}


void read()
{


if(electronics.size() > 0)
{
    cout<<"Chcesz dane z pliku wczytac do nowego pliku czy chcesz najpierw utworzyc nowy?"<<endl;
   cout<<"1. Istniejacego"<<endl;
   cout<<"2. Nowego"<<endl;
   if(getInt(1,2) == 1)
   {
       if(electronics[chooseObject()]->read() == 1)
           cout<<"Wczytywanie z pliku zakonczone pomyslnie"<<endl;
       else
           cout<<"Wczytywanie z pliku zakonczone niepomyslnie"<<endl;
   }
   else
   {
       newObjectRead();
       if(electronics[electronics.size()-1]->read() == 1)
            cout<<"Wczytywanie z pliku zakonczone pomyslnie"<<endl;
       else
       {
            cout<<"Wczytywanie z pliku zakonczone niepomyslnie"<<endl;
            deleteObject(electronics.size()-1);
       }
   }
}
else
{
    newObjectRead();
    if(electronics[electronics.size()-1]->read() == 1)
         cout<<"Wczytywanie z pliku zakonczone pomyslnie"<<endl;
    else
    {
         cout<<"Wczytywanie z pliku zakonczone niepomyslnie"<<endl;
         deleteObject(electronics.size()-1);
    }
}

}

void print()
{
    int index = chooseObject();
    cout<<"******************"<<endl;
    electronics[index]->print();
    cout<<"******************"<<endl;
}





