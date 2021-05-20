#pragma once

#include <iostream>

#include "useful.h"
#include "container.h"

#include "electronic.h"
#include "monitor.h"
#include "computermonitor.h"
#include "hairdryer.h"

using namespace std;

Container<Monitor> monitors;

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
    if(monitors.size() == 0) cout<<"Brak elementow, moze utworzyc nowy?"<<endl;
    else
    {
        for(int i = 1; i <= monitors.size(); i++)
        {
            cout<<i<<": "<<monitors[i].name()<<endl;
        }
    }
}

int menu()
{
    showElementList();

    if(monitors.size() > 0)
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
    return getInt(1, monitors.size());
}
void newElement()
{
    string name;
    cout<<"Prosze podac nazwe monitora: "<<endl;
    cin>>name;

    cout<<"Dodac element na wybrana pozycje w kontenerze(1), czy na koniec kontenera(2)"<<endl;
    if(getInt(1,2) == 1)
    {
        cout<<"Prosze podac pozycje(z zakresu (1,"<<monitors.size()+1<<")"<<endl;
        monitors.push(getInt(1, monitors.size()+1), Monitor(name));
    }
    else
    {
        monitors.push_back(Monitor(name));
    }
}

void deleteElement()
{
    cout<<"Chcesz usunac n-ty element kontenera(1) czy ostatni?(2)"<<endl;
    if(getInt(1,2) == 1)
    {
        cout<<"Prosze podac indeks elementu: "<<endl;
        int i = getInt(1, monitors.size());
        monitors.pop(i);
    }
    else
    {
        monitors.pop_back();
    }
}
void swapElements()
{
    cout<<"Prosze podac nr 1. elementu"<<endl;
    int i = getInt(1, monitors.size());
    cout<<"Prosze podac nr 2. elementu"<<endl;
    int j = getInt(1, monitors.size());
    monitors.swap(i,j);

}
void moveElementToEnd()
{
    cout<<"Prosze podac nr elementu ktory ma wyladowac na koncu: "<<endl;
    monitors.moveToEnd(getInt(1, monitors.size()));
}
void save()
{
    monitors.save();
}
void read()
{
    cout<<"Czy chcesz dopisac elementy do kontenera(1), czy utworzyc nowy z obiektami z pliku(2)?"<<endl;
    if(getInt(1,2) == 1) monitors.read();
    else
    {
        Container<Monitor> helper;
        helper.read();
        monitors = helper;
    }
}

void showElement()
{
    cout<<"Prosze podac nr. elementu:"<<endl;
    monitors[getInt(1, monitors.size())].print();
}
void deleteAllElements()
{
    for(int i = 0; i < monitors.size(); i++)
    {
        monitors.pop_back();
    }
}


