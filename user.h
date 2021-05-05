#pragma once
#include <iostream>

using namespace std;

/// Klasa reprezentująca użytkownika
class User
{
public:

    /// Konstruktor domyślny
    User();

    /// Konstruktor z parametrem
    /**
     \param name_of_user nazwa użytkownika
     */
    User(string name_of_user);

    /// Konstruktor z parametrem
    /**
     \param age_of_user wiek użytkownika
     */
    User(int age_of_user);

    /// Konstruktor z dwoma parametrami
    /**
     \param name_of_user nazwa użytkownika
     \param age_of_user wiek użytkownika
     */
    User(string name_of_user, int age_of_user);

    /// Konstruktor kopiujący
    /**
     \param user_to_copy Referencja do kopiowanego użytkownika
     */
    User(const User &user_to_copy);

    /// Destruktor
   ~User();

    /// Przeciążony operator przypisania
    /**
     \param user_to_copy Użytkownik którego parametry zostaną przypisane
     \return Referencja do użytkownika z przypisanymi parametrami
     */
    User& operator=(const User &user_to_copy);

    /// Zwraca imię
    string name(){return m_name;}

    /// Zwraca wiek
    int age(){return m_age;}

    /// Ustawia imię
    /**
     \param name imię
     */
    void setName(string name) {m_name = name;}

    /// Ustawia wiek
    /**
     \param age wiek
     */
    void setAge(unsigned int age) { m_age = age;}

    /// Przeciążony operator strumienia wyjścia
    friend ostream & operator<<( ostream &s , const User& user);

    /// Przeciążony operator strumienia wejścia
    friend istream & operator>>( istream &s , User& user);
private:
    static int m_quantity; ///> Ilość użytkowników
    string m_name = "anonim"; /// Imię użytkownika
    unsigned int m_age = 18; /// Wiek użytkownika
};


