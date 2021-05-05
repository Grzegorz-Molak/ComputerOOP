#pragma once
#include "electronic.h"
#include <string>

/// Klasa reprezentująca suszarkę
class Hairdryer : public Electronic
{
public:
    /// Typ wyliczeniowy dla poziomu ciepła suszarki
    enum class Heat_level { OFF ,LOW, MEDIUM, HIGH};

    /// Konstruktor domyślny
    Hairdryer();

    /// Konstruktor z parametrem
    /**
     \param name nazwa urządzenia
     */
    Hairdryer(string name);

    /// Destruktor
    ~Hairdryer();

    /// Włącza/Wyłącza urządzenie
    void switchPower();

    /// Zwraca poziom ciepła suszarki
    /**
      @return Poziom ciepła suszarki jako liczba całkowita
     */
    int heat_level();

    /// Ustawia poziom ciepła(interfejs)
    void setHeat_level();

    /// Ustawia poziom ciepła(bez interfejsu)
    /**
     \param heat_level poziom ciepła
     */
    void setHeat_level(Heat_level heat_level);


    /// Zapisuje do pliku
    void save();

    /// Odczytuje z pliku
    int read();

    /// Wypisuje na ekran konsoli
    void print();

    /// Uruchamia edytor
    void edit();

    /// Przedstawia dostępne funkcje
    /**
     \return Zwraca 1, co oznacza że obiekt jest suszarką
     */
    int functions();

    /// Przeciążony operator strumieniowy wyjścia dla suszarki
    friend ostream & operator<<( ostream &s , Hairdryer& hairdryer);

    /// Przeciążony operator strumieniowy wejścia dla typu wyliczonego poziomu ciepła
    friend ostream & operator>>( ostream &s , Hairdryer::Heat_level& heat_level);

    /// Przeciążony operator strumieniowy wejścia dla suszarki
    friend istream & operator>>( istream &s , Hairdryer& hairdryer);

private:
    Heat_level m_heat_level = Heat_level::OFF; ///< Poziom ciepła, domyślnie OFF
    static int m_quantity; /// Ilość suszarek
};

