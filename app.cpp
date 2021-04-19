#include "app.h"

int App::m_quantity = 0; // bazowo ilosc aplikacji to 0

// KONSTRUKTORY **********

App::App() // podstawowy konstruktor
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"App(), 'App' objects: "<<m_quantity<<endl;
#endif  
}

App::App(string name_of_app) // konstruktor jezeli podano nazwe aplikacji
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"App("<<name_of_app<<"), 'App' objects: "<<m_quantity<<endl;
#endif
    this->m_name = name_of_app;
}

App::App(const App &app_to_copy) // konstruktor kopiujacy
{
    m_quantity++;
#ifdef _DEBUG
    cout<<"App(const App &app_to_copy), 'App' objects: "<<m_quantity<<endl;
#endif
    this->m_name = app_to_copy.m_name;
}

// KONSTRUKTORY **********


App::~App() // destruktor
{
    m_quantity--;
#ifdef _DEBUG
    if(m_name == "unknown")
    {
       cout<<"~App(), 'App' objects: "<<m_quantity<<endl;
    }
    else
    {
        cout<<"~App("<<m_name<<"), 'App' objects: "<<m_quantity<<endl;
    }

#endif   
}


// OPERATORY *****************************

App& App::operator=(const App &app_to_copy) //operator przypisania, mozna przypisac obiektowi App wartosc(bedzie to nazwa)
{
    m_name = app_to_copy.m_name;
    return *this;
}

// OPERATORY *****************************

// INNE FUNKCJE

void App::setName(string name)
{
#ifdef _DEBUG
    cout<<"Replacing "<<m_name<<" with "<<name<<endl;
#endif
    m_name = name;
}


