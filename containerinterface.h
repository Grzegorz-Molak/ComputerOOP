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
Container<Hairdryer> hairdryers;
Container<ComputerMonitor> computers;
int active = 1;

void interface();
int menu();
void showElementList();
int chooseElement();
void newElement();
void deleteElement();
void swapElements();
void moveElementToEnd();
void edit();
void save();
void setActive();
void read();
void showElement();
void deleteAllElements();

void interface()
{
    bool end = false;
    setActive();
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
            edit();
            break;
        case 6:
            save();
            break;
        case 7:
            read();
            break;
        case 8:
            showElement();
            break;
        case 9:
            setActive();
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
    if(active == 1)
    {
        cout<<"Suszarki:"<<endl;
        if(hairdryers.size() == 0) cout<<"Brak suszarek, moze utworzyc nowa?"<<endl;
        else
        {
            for(int i = 1; i <= hairdryers.size(); i++)
            {
                cout<<i<<": "<<hairdryers[i].name()<<endl;
            }
        }
    }
    else if(active == 2)
    {
        cout<<"Monitory:"<<endl;
        if(monitors.size() == 0) cout<<"Brak monitorow, moze utworzyc nowy?"<<endl;
        else
        {
            for(int i = 1; i <= monitors.size(); i++)
            {
                cout<<i<<": "<<monitors[i].name()<<endl;
            }
        }
    }
    else
    {
        cout<<"Monitory komputerowe:"<<endl;
        if(computers.size() == 0) cout<<"Brak monitorow komputerowych, moze utworzyc nowy?"<<endl;
        else
        {
            for(int i = 1; i <= computers.size(); i++)
            {
                cout<<i<<": "<<computers[i].name()<<endl;
            }
        }
    }

}

int menu()
{
    showElementList();




    if((active == 1 && hairdryers.size() > 0) ||
            (active == 2 && monitors.size() > 0) ||
            (active == 3 && computers.size() > 0))
    {
        cout<<"\nWybierz dzialanie: "<<endl;
        cout<<"******************************"<<endl;
        cout<<"1 - Dodaj nowy element"<<endl;
        cout<<"2 - Usun element"<<endl;
        cout<<"3 - Zamien obiekty miejscami"<<endl;
        cout<<"4 - Przenies obiekt na koniec kontenera"<<endl;
        cout<<"5 - Edytuj element"<<endl;
        cout<<"6 - Zapisz kontener do pliku"<<endl;
        cout<<"7 - Wczytaj kontener z pliku"<<endl;
        cout<<"8 - Wyswietl obiekt"<<endl;
        cout<<"9 - ustaw aktywny kontener"<<endl;
        cout<<"0 - By opuscic program"<<endl;
        cout<<"******************************"<<endl;
        return getInt(0,9);
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
        if(index == 2) return 7;
        else return index;
    }
}



int chooseElement()
{
    cout<<"Wybierz element z kontenera poslugujac sie jego indeksem(po lewej stronie)"<<endl;
    if(active == 1) return getInt(1, hairdryers.size());
    else if(active == 2) return getInt(1, monitors.size());
    else return getInt(1, computers.size());
}
void newElement()
{
    string name;
    if(active == 1) cout<<"Prosze podac nazwe suszarki: "<<endl;
    else if(active == 2) cout<<"Prosze podac nazwe monitora: "<<endl;
    else cout<<"Prosze podac nazwe monitora komputerowego: "<<endl;

    cin>>name;

    if(active == 1)
    {
        if(hairdryers.size() >= 1)
        {
            cout<<"Dodac element na wybrana pozycje w kontenerze(1), czy na koniec kontenera(2)"<<endl;
            if(getInt(1,2) == 1)
            {
                cout<<"Prosze podac pozycje(z zakresu (1,"<<hairdryers.size()+1<<")"<<endl;
                hairdryers.push(getInt(1, hairdryers.size()+1), Hairdryer(name));
            }
            else
            {
                hairdryers.push_back(Hairdryer(name));
            }
        }
        else
        {
            hairdryers.push_back(Hairdryer(name));
        }
    }
    else if(active == 2)
    {
        if(monitors.size() >= 1)
        {
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
        else
        {
            monitors.push_back(Monitor(name));
        }
    }
    else
    {
        if(computers.size() >= 1)
        {
            cout<<"Dodac element na wybrana pozycje w kontenerze(1), czy na koniec kontenera(2)"<<endl;
            if(getInt(1,2) == 1)
            {
                cout<<"Prosze podac pozycje(z zakresu (1,"<<computers.size()+1<<")"<<endl;
                computers.push(getInt(1, computers.size()+1), ComputerMonitor(name));
            }
            else
            {
                computers.push_back(ComputerMonitor(name));
            }
        }
        else
        {
            computers.push_back(ComputerMonitor(name));
        }
    }

}

void deleteElement()
{
    if(active == 1)
    {
        if(hairdryers.size() > 1)
        {
            cout<<"Chcesz usunac n-ty element kontenera(1) czy ostatni?(2)"<<endl;
            if(getInt(1,2) == 1)
            {
                cout<<"Prosze podac indeks elementu: "<<endl;
                int i = getInt(1, hairdryers.size());
                hairdryers.pop(i);
            }
            else
            {
                hairdryers.pop_back();
            }
        }
        else
        {
            hairdryers.pop_back();
        }
    }
    else if(active == 2)
    {
        if(monitors.size() > 1)
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
        else
        {
            monitors.pop_back();
        }
    }
    else
    {
        if(computers.size() > 1)
        {
            cout<<"Chcesz usunac n-ty element kontenera(1) czy ostatni?(2)"<<endl;
            if(getInt(1,2) == 1)
            {
                cout<<"Prosze podac indeks elementu: "<<endl;
                int i = getInt(1, computers.size());
                computers.pop(i);
            }
            else
            {
                computers.pop_back();
            }
        }
        else
        {
            computers.pop_back();
        }
    }
}

void swapElements()
{
    if(active == 1)
    {
        cout<<"Prosze podac nr 1. elementu"<<endl;
        int i = getInt(1, hairdryers.size());
        cout<<"Prosze podac nr 2. elementu"<<endl;
        int j = getInt(1, hairdryers.size());
        hairdryers.swap(i,j);
    }
    else if(active == 2)
    {
        cout<<"Prosze podac nr 1. elementu"<<endl;
        int i = getInt(1, monitors.size());
        cout<<"Prosze podac nr 2. elementu"<<endl;
        int j = getInt(1, monitors.size());
        monitors.swap(i,j);
    }
    else
    {
        cout<<"Prosze podac nr 1. elementu"<<endl;
        int i = getInt(1, computers.size());
        cout<<"Prosze podac nr 2. elementu"<<endl;
        int j = getInt(1, computers.size());
        computers.swap(i,j);
    }

}
void moveElementToEnd()
{
    cout<<"Prosze podac nr elementu ktory ma wyladowac na koncu: "<<endl;
    if(active == 1) hairdryers.moveToEnd(getInt(1, hairdryers.size()));
    else if(active == 2) monitors.moveToEnd(getInt(1, monitors.size()));
    else computers.moveToEnd(getInt(1, computers.size()));
}

void edit()
{
    cout<<"Prosze podac nr elementu do edycji: "<<endl;
    if(active == 1) hairdryers[getInt(1, hairdryers.size())].edit();
    else if(active == 2) monitors[getInt(1, monitors.size())].edit();
    else computers[getInt(1, computers.size())].edit();
}

void save()
{
    if(active == 1) hairdryers.save();
    else if(active == 2) monitors.save();
    else  computers.save();
}
void read()
{
    cout<<"Czy chcesz dopisac elementy do kontenera(1), czy utworzyc nowy z obiektami z pliku(2)?"<<endl;
    if(active == 1)
    {
        if(getInt(1,2) == 1) hairdryers.read();
        else
        {
            Container<Hairdryer> helper;
            helper.read();
            hairdryers = helper;
        }
    }
    else if(active == 2)
    {
        if(getInt(1,2) == 1) monitors.read();
        else
        {
            Container<Monitor> helper;
            helper.read();
            monitors = helper;
        }
    }
    else
    {
        if(getInt(1,2) == 1) computers.read();
        else
        {
            Container<ComputerMonitor> helper;
            helper.read();
            computers = helper;
        }
    }
}

void showElement()
{
    cout<<"Prosze podac nr. elementu:"<<endl;
    if(active == 1) hairdryers[getInt(1, hairdryers.size())].print();
    else if(active == 2) monitors[getInt(1, monitors.size())].print();
    else computers[getInt(1, computers.size())].print();
}
void deleteAllElements()
{
    for(int i = 0; i < hairdryers.size(); i++)
    {
        hairdryers.pop_back();
    }
    for(int i = 0; i < monitors.size(); i++)
    {
        monitors.pop_back();
    }
    for(int i = 0; i < computers.size(); i++)
    {
        computers.pop_back();
    }

}

void setActive()
{
    cout<<"Chcesz aktywowac: suszarki(1), monitory(2), monitory komputerowe(3)?"<<endl;

    active = getInt(1,3);
}


