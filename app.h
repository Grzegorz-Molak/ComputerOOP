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

    static int quantity();

    App& operator=(const App &app_to_copy); // przypisuje danej aplikacji parametry innej

    // funkcje sterujace zawartoscia ******
    string name();
    void setName(string name);
    // funkcje sterujace zawartoscia ******

    friend ostream & operator<<( ostream &s , App& app);
    friend istream & operator>>( istream &s , App& app);

private:
    static int m_quantity;
    string m_name = "unknown"; // bazowo kazda aplikacja ma nazwe unknown
};

