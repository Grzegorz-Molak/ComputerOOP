#pragma once

#include <iostream>

#include "useful.h"
#include "container.h"

#include "electronic.h"
#include "monitor.h"
#include "computermonitor.h"
#include "hairdryer.h"

using namespace std;

Container<Electronic*> electronics;

void interface();
int menu();
void showElementList();
int chooseElement();
void newElement();
void deleteElement();
void swapElements();
void moveElementToEnd();
void save();
void read();
void showElement();
void deleteAllElements();

void interface()
{
    bool end = false;
    while(!end)
    {
        switch(menu())
        {
            case 1:
                newElement();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                swapElements();
                break;
            case 4:
                moveElementToEnd();
                break;
            case 5:
                save();
                break;
            case 6:
                read();
                break;
            case 7:
                showElement();
                break;
            case 0:
                end = true;
                deleteAllElements();
                break;
        }
    }
}

void showElementList()
{
    if(electronics.size() == 0) cout<<"Brak elementow, moze utworzyc nowy?"<<endl;
    else
    {
        for(int i = 1; i <= electronics.size(); i++)
        {
            cout<<i<<": "<<electronics[i]->name()<<endl;
        }
    }
}

int menu()
{
    showElementList();

    if(electronics.size() > 0)
    {
    cout<<"\nWybierz dzialanie: "<<endl;
    cout<<"******************************"<<endl;
    cout<<"1 - Dodaj nowy element"<<endl;
    cout<<"2 - Usun element"<<endl;
    cout<<"3 - Zamien obiekty miejscami"<<endl;
    cout<<"4 - Przenies obiekt na koniec kontenera"<<endl;
    cout<<"5 - Zapisz kontener do pliku"<<endl;
    cout<<"6 - Wczytaj kontener z pliku"<<endl;
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
        cout<<"2 - Wczytaj kontener z pliku"<<endl;
        cout<<"0 - By opuscic program"<<endl;
        cout<<"******************************"<<endl;
        int index = getInt(0,2);
        if(index == 2) return 6;
        else return index;
    }
}



int chooseElement()
{
    cout<<"Wybierz element z kontenera poslugujac sie jego indeksem(po lewej stronie)"<<endl;
    return getInt(1, electronics.size());
}
void newElement()
{
    string name;
    cout<<"Prosze podac nazwe elementu: "<<endl;
    cin>>name;

    cout<<"Czym jest "<<name<<"? Prosze wybrac 1,2 albo 3"<<endl;
    cout<<"1: Suszarka"<<endl;
    cout<<"2: Monitor"<<endl;
    cout<<"3: Monitor komputerowy"<<endl;

    int type = getInt(1,3);


    cout<<"Dodac element na wybrana pozycje w kontenerze(1), czy na koniec kontenera(2)"<<endl;
    if(getInt(1,2) == 1)
    {
        cout<<"Prosze podac pozycje(z zakresu (1,"<<electronics.size()+1<<")"<<endl;
        switch(type)
        {
            case 1:
                electronics.push(getInt(1,electronics.size()+1) ,new Hairdryer(name));
                break;
            case 2:
                electronics.push(getInt(1,electronics.size()+1) ,new Monitor(name));
                break;
            case 3:
                electronics.push(getInt(1,electronics.size()+1) ,new ComputerMonitor(name));
                break;
        }
    }
    else
    {
        switch(type)
        {
            case 1:
                electronics.push_back(new Hairdryer(name));
                break;
            case 2:
                electronics.push_back(new Monitor(name));
                break;
            case 3:
                electronics.push_back(new ComputerMonitor(name));
                break;
        }
    }
}

void deleteElement()
{
    cout<<"Chcesz usunac n-ty element kontenera(1) czy ostatni?(2)"<<endl;
    if(getInt(1,2) == 1)
    {
        cout<<"Prosze podac indeks elementu: "<<endl;
        int i = getInt(1, electronics.size());
        delete electronics[i];
        electronics.pop(i);
    }
    else
    {
        delete electronics[electronics.size()];
        electronics.pop_back();
    }
}
void swapElements()
{
    cout<<"Prosze podac nr 1. elementu"<<endl;
    int i = getInt(1, electronics.size());
    cout<<"Prosze podac nr 2. elementu"<<endl;
    int j = getInt(1, electronics.size());
    electronics.swap(i,j);

}
void moveElementToEnd()
{
    cout<<"Prosze podac nr elementu ktory ma wyladowac na koncu: "<<endl;
    electronics.moveToEnd(getInt(1, electronics.size()));
}
void save()
{
    electronics.save();
}
void read()
{
    cout<<"Chcesz dopisac elementy do kontenera(1), czy zastapic tymi elementami aktualny kontener?(2)"<<endl;
    if(getInt(1,2) == 1)
    {
        //electronics.read();
    }
    else
    {
        Container<Electronic*> helper;
        //helper.read();
        electronics = helper;
    }
}

void showElement()
{
    cout<<"Prosze podac nr. elementu:"<<endl;
    electronics[getInt(1, electronics.size())]->print();
}
void deleteAllElements()
{
    for(int i = 0; i < electronics.size(); i++)
    {
        delete electronics[electronics.size()];
        electronics.pop_back();
    }
}


