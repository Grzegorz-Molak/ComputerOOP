#pragma once
#include <string>
#include "user.h"

using namespace std;
/// Klasa reprezentująca sprzęt elektroniczny
class Electronic
{
public:
    /// Konstruktor domyślny
    Electronic();

    /// Destruktor(wirtualny)
    virtual ~Electronic();

    /// Zwraca czy urządzenie jest ON(typ logiczny)
    bool power() const;

    /// Włącza/Wyłącza urządzenie(metoda czysto wirtualna)
    virtual void switchPower() = 0;

    /// Pyta użytkownika czy chce włączyć urządzenie
    bool askToTurnOn();

    /// Zwraca nazwę
    string name() const;

    /// Zmienia nazwę urządzenia
    /**
     \param name nowa nazwa urządzenia
     */
    void setName(const string &name);

    /// Zwraca użytkownika
    User user() const;

    /// zmienia użytkownia
    /**
     \param user referencja do użytkownika
     */
    void setUser(const User &user);

    /// Zapis do pliku(metoda czysto wirtualna)
    virtual void save() = 0;

    /// Odczyt z pliku(metoda czysto wirtualna)
    virtual int read() = 0;

    /// Wypisanie w konsoli(metoda czysto wirtualna)
    virtual void print() = 0;

    /// Włącza edytyor urządzenia elektrycznego
    virtual void edit();

    /// Przedstawia dostępne funkcje
    /**
    \return Zwraca 0
    */
    virtual int functions();

    /// Przeciążony operator strumieniowy wyjścia
    friend ostream & operator<<( ostream &s , const Electronic& electronic);
    /// Przeciążony operator strumieniowy wejścia
    friend istream & operator>>( istream &s , Electronic& electronic);

protected:
    bool m_power = 0; ///< włączenie urządzenia(typ logiczny), domyślnie OFF
    string m_name = "unknown"; /// nazwa urządzenia, domyślnie unknown
    User m_user; /// Użytkownik urządzenia

 private:
    static int m_quantity; /// Ilość sprzętów elektronicznych
};

