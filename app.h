#pragma once
#include <iostream>

using namespace std;
/// Klasa reprezentująca Aplikację
class App
{
public:

    /// Konstruktor domyślny
    App();

    /// Konstruktor z parametrem
    /**
     \param name_of_app nazwa aplikacji
     */
    App(string name_of_app);

    /// Konstruktor kopiujący
    /**
     \param app_to_copy aplikacja do skopiowania
     */
    App(const App &app_to_copy);

    /// Destruktor
   ~App();

    /// Przeciążony operator przypisania(operator = )
    /**
     \param app_to_copy aplikacja, której parametry zostaną przypisane
     \return zwraca referencję do nowej wersji aplikacji
     */
    App& operator=(const App &app_to_copy);

    /// zwraca nazwę aplikacji
    string name();

    /// zmienia nazwę aplikacji
    /**
     \param name nowa nazwa aplikacji
     */
    void setName(string name);

    /// Przeciążony operator strumieniowy wyjścia
    friend ostream & operator<<( ostream &s , App& app);

    /// Przeciążony operator strumieniowy wejścia
    friend istream & operator>>( istream &s , App& app);

private:
    static int m_quantity; ///< ilość otwartych aplikacji
    string m_name = "unknown"; ///< nazwa aplikacji(domyślnie unknown)
};

