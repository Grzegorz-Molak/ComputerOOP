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

    static int quantity() {return m_quantity;}

    App& operator=(const App &app_to_copy); // przypisuje danej aplikacji parametry innej

    // funkcje sterujace zawartoscia ******
    string name() { return m_name;}
    void setName(string name);
    // funkcje sterujace zawartoscia ******

private:
    static int m_quantity;
    string m_name = "unknown"; // bazowo kazda aplikacja ma nazwe unknown
};

