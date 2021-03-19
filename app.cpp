#include "app.h"

unsigned int App::quantity = 0; // bazowo ilosc aplikacji to 0

// KONSTRUKTORY **********

App::App() // podstawowy konstruktor
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(), current number of class 'App' objects: "<<quantity<<endl;
#endif  
}

App::App(string name_of_app) // konstruktor jezeli podano nazwe aplikacji
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(string name_of_app), current number of class 'App' objects: "<<quantity<<endl;
#endif
    this->name = name_of_app;
}

App::App(const App &app_to_copy) // konstruktor kopiujacy
{
    quantity++;
#ifdef _DEBUG
    cout<<"App(const App &app_to_copy), current number of class 'App' objects: "<<quantity<<endl;
#endif
    this->name = app_to_copy.name;
}

// KONSTRUKTORY **********

App::~App() // destruktor
{
    quantity--;
#ifdef _DEBUG
    cout<<"~App(), current number of class 'App' objects: "<<quantity<<endl;
#endif   
}


// OPERATORY *****************************

App& App::operator=(const App &app_to_copy) //operator przypisania, mozna przypisac obiektowi App wartosc(bedzie to nazwa)
{
    name = app_to_copy.name;
    return *this;
}

// OPERATORY *****************************


