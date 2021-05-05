#pragma once
#include "app.h"
#include "monitor.h"

/// Klasa reprezentująca monitor komputerowy
class ComputerMonitor : public Monitor
{

public:
    /// Typ wyliczeniowy dla typów wyjść monitora komputerowego
    enum class Output { VGA, DVI, HDMI, DISPLAYPORT};

    /// Konstruktor domyślny
    ComputerMonitor();

    /// Konstruktor z jednym parametrem
    /**
     \param name nazwa monitora komputerowego
     */
    ComputerMonitor(string name);

    /// Konstruktor z jednym parametrem
    /**
     \param name nazwa monitora komputerowego
     \param output typ nowego wyjścia
     */
    ComputerMonitor(string name, Output output);

    /// Destruktor
    ~ComputerMonitor();

    /// Włącza/Wyłącza urządzenie
    void switchPower();

    /// Otwiera nową aplikację
    /**
     \param name nazwa aplikacji
     */
    void openApp(string name);

    /// Zamyka aplikację na szczycie stosu
    void closeApp();

    /// Zwraca wyjście
    Output output();

    /// Ustawia wyjście(interfejs)
    void setOutput();

    /// Ustawia wyjście(bez interfejsu)
    /**
     \param output typ wyjścia
     */
    void setOutput(Output output);

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
     \return Zwraca 3, co oznacza że obiekt jest monitorem komputerowym
     */
    int functions();

    /// Przeciążony operator strumienia wyjścia dla klasy ComputerMonitor
    friend ostream& operator<<(ostream &, const ComputerMonitor&);

    /// Przeciążony operator strumienia wejścia dla klasy ComputerMonitor
    friend istream & operator>>( istream &s , ComputerMonitor& computermonitor);

    /// Przeciążony operator strumienia wejścia dla typu wyliczeniowego Output
    friend istream & operator>>( istream &s , ComputerMonitor::Output& output);

protected:
    Output m_output = Output::VGA; ///< Wyjście komputera monitorowego, domyślnie VGA

private:
   static int m_quantity; /// Ilość monitorów komputerowych
};
