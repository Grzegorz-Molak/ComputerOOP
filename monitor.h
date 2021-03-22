#pragma once
#include "user.h"
#include "app.h"

using namespace std;

class Monitor
{
public:
    // KONSTRUKTORY **********
    Monitor();
    Monitor(string model_name);
    Monitor(unsigned int users_number);
    Monitor(string model_name, unsigned int users_number);
    Monitor(const Monitor &monitor_to_copy);
    // KONSTRUKTORY **********
    ~Monitor(); // DESTRUKTOR ************

    static int get_quantity() {return quantity;}

    // Metody pobierajace wartosci
    unsigned int get_number_of_apps() {return number_of_apps;}
    App* get_apps() {return opened_apps;}
    User* get_user(){return &user;}
    string get_model(){return name_of_model;}
    // Metody pobierajace wartosci

    // Przeciazone operatory **********
    bool operator==(const Monitor &monitor_to_compare); // porownoje czy dwa monitory to ten sam model
    Monitor& operator=(const Monitor &monitor_to_copy); // przypisuje monitorowi parametry innego
    operator string(); // zwraca string, w ktorym sa skrotowe informacje o monitorze
    App* operator[](unsigned int i); //zwraca adres do itej aplikacji
    Monitor& operator!(); // zmienia stan ekranu gasi i zapala

    friend
    ostream & operator<<( ostream &s , Monitor& monitor_to_ostream); // wypisuje informacje o monitorze
    // Przeciazone operatory **********

private:
    static unsigned int quantity; // ilosc obiektow w klasie
    string name_of_model = "unknown";
    bool screen_on = true;
    unsigned int number_of_apps = 0;
    User user;
    App *opened_apps = 0;
};


