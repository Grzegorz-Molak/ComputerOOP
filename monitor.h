#pragma once
#include <stack>
#include "electronic.h"
#include "app.h"

using namespace std;

/// Klasa reprezentująca monitor
class Monitor : public Electronic
{
public:
    /// Konsturktor domyślny
    Monitor();

    /// Konstruktor z parametrem
    /**
     \param name nazwa urządzenia
     */
    Monitor(string name);

    /// Destruktor
    ~Monitor();

    /// Zwraca przekątną
    double diagonal() const;

    /// Ustawia przekątną
    /**
     \param diagonal długość przekątnej
     */
    void setDiagonal(double diagonal);

    /// Zwraca jasność
    unsigned int getBrightness() const;

    /// Ustawia jasność
    /**
     \param value jasność
     */
    void setBrightness(unsigned int value);


    /// Włącza/Wyłącza urządzenie
    void switchPower();

    /// Otwiera aplikację(zamykając poprzednią)
    /**
     /param name Nazwa aplikacji
     */
    virtual void openApp(string name);

    /// Zamyka aplikację i otwiera aplikację domyślną Hello World
    void closeApp();

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
     \return Zwraca 2, co oznacza że obiekt jest monitorem
     */
    int functions();

    /// Przeciążony operator strumieniowy wyjścia
    friend ostream & operator<<( ostream &s , const Monitor& monitor);

    /// Przeciążony operator strumieniowy wejścia
    friend istream & operator>>( istream &s , Monitor& monitor);

protected:
    double m_diagonal = 25; ///< Długość przekątnej, domyślna wartość 25
    unsigned int m_brightness = 50; ///< Jasność, domyślna wartość 50
    stack<App> m_apps; /// Stos aplikacji, monitor może mieć otwartą tylko jedną

private:
   static int m_quantity; /// Ilość monitorów
};


