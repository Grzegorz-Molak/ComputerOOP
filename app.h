#pragma once
#include <iostream>

using namespace std;

class App // Aplikacja
{
public:
    // KONSTRUKTORY **********
    App();
    App(string name_of_app);
    App(const App &app_to_copy);
    // KONSTRUKTORY **********
   ~App(); // DESTRUKTOR ***********

    static int get_quantity() {return quantity;}

    App& operator=(const App &app_to_copy); // przypisuje danej aplikacji parametry innej

    // funkcje sterujace zawartoscia ******
    string get_name() { return this->name;}
    void set_name(string new_name);
    // funkcje sterujace zawartoscia ******

private:
    static unsigned int quantity;
    string name = "unknown"; // bazowo kazda aplikacja ma nazwe unknown
};

