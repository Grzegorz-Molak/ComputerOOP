#pragma once
#include "node.h"
#include "iostream"
#include "fstream"

using namespace std;

template<class T>
class Container
{
public:
    Container() {} // Domyslny konstruktor
    Container(const Container<T>& c); // Konstruktor kopiujacy
    ~Container(); // Destruktor

    Container& operator=(const Container<T>& c); // Operator przypisania
    bool operator==(const Container<T>& c); // Operator porówania
    T& operator[](int i); // Operator indeksowy

    friend std::ostream& operator<<(std::ostream &s, Container &c) // Wypisuje dane na strumien
    {
        Node<T>* ptr = c.begin();
        for(int i = 1; i <= c.size(); i++)
        {
            if(!ptr) throw string("Luka w kontenerze\n");
            s<<i<<": "<<ptr->getObject()<<endl;
            ptr = ptr->next();

        }
        return s;
    }
    friend istream & operator>>(istream& s, Container &c) // Wczytuje ze strumienia
    {
        string title;
        T obj;
        s>>title>>obj; // bo sa numerowane 1. 2. 3. ...
        if(!s.eof() && s) c.push_back(obj);
        return s;
    }

    void push_back(T elem); // Tworzy element na koncu listy
    void push(int pos, T elem); // Tworzy element na n-tej pozycji listy

    void pop_back(); // Usuwa ostatni element listy
    void pop(int pos); // Usuwa n-ty element listy

    void swap(int e1, int e2); // Zamienia elementy miejscami
    void moveToEnd(int n); // Przenosi element na koniec listy

    void save(); // Zapisuje do pliku
    void read(); // Odczytuje z pliku



    Node<T> *begin() const {return m_begin;} // Zwraca wskaznik na poczatek listy
    void setBegin(Node<T> *begin) { m_begin = begin;}  // Ustawia wskaznik na poczatek listy

    Node<T> *end() const { return m_end;} //  Zwraca wskaznik na koniec listy
    void setEnd(Node<T> *end) { m_end = end;} // Ustawia wskaznik na koniec listy

    void setSize(int size) {m_size = size;} // Ustawia rozmiar listy
    int size() const { return m_size;} // Zwraca rozmiar listy

private:
    Node<T>* at(int pos); // Zwraca wskaznik na i-ty element listy
    Node<T>* m_begin = nullptr; // wskaznik na glowe listy
    Node<T>* m_end = nullptr; // wskaznik na ogon listy
    int m_size = 0; // rozmiar listy

};


// ***********************************************
template<class T>
Container<T>::Container(const Container<T>& c)
{
    Node<T>* ptr = c.begin();
    while(ptr != nullptr)
    {
        push_back(ptr->value());
        ptr = ptr->next();
    }
}

template<class T>
Container<T>::~Container()
{
    try
    {
        Node<T>* ptr = begin();
        Node<T>* p_ptr = ptr;
        while(ptr)
        {
            p_ptr = ptr;
            ptr = ptr->next();
            delete p_ptr;
            setSize(size() - 1);
        }
        if(size() > 0) throw string("Nie udalo sie usunac wszystkich elementow");
    }
    catch (string s)
    {
        cout<<s;
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }
}

template<class T>
Container<T>& Container<T>::operator=(const Container<T>& c)
{
    while(size() > 0)
    {
        pop_back();
    }
    Node<T>* ptr = c.begin();
    while(ptr != nullptr)
    {
        push_back(ptr->value());
        ptr = ptr->next();
    }

    return *this;
}

template<class T>
bool Container<T>::operator==(const Container<T>& c)
{
    if(size() != c.size())
    {
        return false;
    }
    else
    {
        Node<T>* ptr1 = begin();
        Node<T>* ptr2 = c.begin();
        while(ptr1->next() != nullptr && ptr2->next() != nullptr)
        {
            if(ptr1->value() != ptr2->value()) return false;
            ptr1 = ptr1->next();
            ptr2 = ptr2->next();
        }
        return true;
    }
}

template<class T>
T& Container<T>::operator[](int i)
{
    return at(i)->getObject();
}

template<class T>
void Container<T>::moveToEnd(int n)
{
    //push_back(at(n)->value());
    //pop(n);
    if(n == size())
    {
        return;
    }
    else if(size() == 2)
    {
        swap(1,2);
    }
    else if(n == 1)
    {
        Node<T>* ptr = begin();
        setBegin(begin()->next());

        ptr->setNext(nullptr);
        ptr->setPrevious(end());
        end()->setNext(ptr);
        setEnd(ptr);

    }
    else
    {
        try
        {
            Node<T>* ptr = at(n);
            ptr->previous()->setNext(ptr->next());
            ptr->next()->setPrevious(ptr->previous());

            ptr->setPrevious(end());
            ptr->setNext(nullptr);
            end()->setNext(ptr);
            setEnd(ptr);
        }
        catch (string s)
        {
            cout<<s;
        }
        catch (exception)
        {
            cout<<"Wystapil nieznany blad\n";
        }
    }
}


template<class T>
Node<T>* Container<T>::at(int pos)
{
        Node<T>* ptr;
        if(pos > size())
        {
            throw string("Nie mozna uzyskac dostepu do elementu indeksie "+to_string(pos)+", zakres to <1,"+to_string(size())+">\n");
        }
        else if(pos < size()/2)
        {
            ptr = begin();
            for(int i = 1; i < pos; i++)
            {
                if(ptr->next() == nullptr && i < pos )
                {
                    throw string("Wystapila luka w kontenerze\n");
                }
                ptr = ptr->next();
            }
        }
        else
        {
            ptr = end();
            for(int i = size(); i > pos; i--)
            {
                if(ptr->previous() == nullptr && i > pos )
                {
                    throw string("Wystapila luka w kontenerze\n");
                }
                ptr = ptr->previous();
            }
        }
        return ptr;
}

template<class T>
void Container<T>::push_back(T elem)
{
    push(size()+1, elem);
}

template<class T>
void Container<T>::push(int pos, T elem)
{
    try
    {
        if(size() == 0)
        {
            setBegin(new Node<T>(elem));
            setEnd(begin());
            setSize(size()+1);
        }
        else if(pos <= size())
        {
            Node<T>* ptr;
            try
            {
                ptr = at(pos);
                Node<T>* new_node = new Node<T>(elem, ptr->previous(), ptr);
                //if(!new_node) throw string("Blad alokowania pamieci");
                ptr->setPrevious(new_node);
                if(new_node->previous()) (new_node->previous())->setNext(new_node);
                else setBegin(new_node);
                setSize(size()+1);
            }
            catch (string s)
            {
                cout<<s;
            }
            catch (exception)
            {
                cout<<"Wystapil nieznany blad\n";
            }
        }
        else if(pos == size()+1)
        {
            Node<T>* former_end = end();
            Node<T>* new_end = new Node<T>(elem, former_end);
            //if(!new_end) throw string("Blad alokowania pamieci");
            setEnd(new_end);
            former_end->setNext(new_end);
            setSize(size()+1);
        }
        else
        {
            cout<<"Nie mozna utworzyc elementu o takim indeksie, zakres to <1,"<<size()+1<<">\n";
        }
    }
    catch(string s)
    {
        cout<<s;
    }
    catch(bad_alloc)
    {
        cout<<"Blad alokowania pamieci\n";
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }
}

template<class T>
void Container<T>::pop(int pos)
{
    try
    {
        if(pos > size())
        {
            throw string("Nie mozna usunac elementu o takim indeksie, zakres to <1,"+to_string(size())+">\n");
        }
        else if(size() == 0)
        {
            throw string("Nie ma czego usuwac");
        }
        else if(size() == 1)
        {
            delete begin();
            setBegin(nullptr);
            setEnd(nullptr);
            setSize(size()-1);

        }
        else if(pos == 1)
        {
            Node<T>* ptr = begin();
            if(!(begin()->next())) throw string("Wystapila luka w kontenerze");
            (begin()->next())->setPrevious(nullptr);
            setBegin(ptr->next());
            delete ptr;
            setSize(size()-1);
        }
        else if(pos == size())
        {
            Node<T>* ptr = end();
            if(!(end()->previous())) throw string("Wystapila luka w kontenerze");
            (end()->previous())->setNext(nullptr);
            setEnd(end()->previous());
            delete ptr;
            setSize(size()-1);
        }
        else
        {
            delete at(pos);
            setSize(size()-1);
        }
    }
    catch(string s)
    {
        cout<<s;
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }
}

template<class T>
void Container<T>::pop_back()
{
    pop(size());
}

template<class T>
void Container<T>::swap(int e1, int e2)
{
    try
    {
        Node<T>* ptr1 = at(e1);
        Node<T>* ptr2 = at(e2);
        if(!ptr1 || !ptr2) throw string("Nie udalo sie odnalezc ktoregos elementu");
        Node<T>* helper_p = ptr1->previous();
        Node<T>* helper_n = ptr1->next();
        if(e1 == e2)
        {
            return;
        }
        if(e1 > e2)
        {
            swap(e2,e1);
        }
        else if(size() == 2)
        {
            setBegin(ptr2);
            setEnd(ptr1);
            ptr1->setNext(nullptr);
            ptr1->setPrevious(ptr2);
            ptr2->setNext(ptr1);
            ptr2->setPrevious(nullptr);
        }
        else if(ptr1->next() == ptr2)
        {
            if(ptr1 == begin()) setBegin(ptr2);
            else ptr1->previous()->setNext(ptr2);

            if(ptr2 == end()) setEnd(ptr1);
            else ptr2->next()->setPrevious(ptr1);

            if(ptr1 == end()) ptr1->setNext(nullptr);
            else ptr1->setNext(ptr2->next());
            ptr1->setPrevious(ptr2);

            ptr2->setNext(ptr1);
            if(ptr2 == begin()) ptr2->setPrevious(nullptr);
            else ptr2->setPrevious(helper_p);
        }
        else
        {
            if(ptr1 == begin()) setBegin(ptr2);
            else ptr1->previous()->setNext(ptr2);
            ptr1->next()->setPrevious(ptr2);

            ptr2->previous()->setNext(ptr1);
            if(ptr2 == end()) setEnd(ptr1);
            else ptr2->next()->setPrevious(ptr1);

            ptr1->setPrevious(ptr2->previous());
            if(ptr1 == end()) ptr1->setNext(nullptr);
            else ptr1->setNext(ptr2->next());

            if(ptr2 == begin()) ptr2->setPrevious(nullptr);
            else ptr2->setPrevious(helper_p);
            ptr2->setNext(helper_n);
        }


    }
    catch (string s)
    {
        cout<<s;
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }

}

template<class T>
void Container<T>::save()
{
    try
    {
        string filename;
        cout<<"Prosze podac nazwe pliku: "<<endl;
        cin>>filename;

        ofstream file;
        file.open(filename+".txt");
        if(!file) throw string("Nie udalo sie utworzyc pliku\n");

        file<<*this;

        file.close();
    }
    catch (string s)
    {
        cout<<s;
    }
    catch (length_error)
    {
        cout<<"wprowadzono za dluga nazwe\n";
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }
}

template<class T>
void Container<T>::read()
{
    try
    {
        string filename;
        cout<<"Prosze podac nazwe pliku: "<<endl;
        cin>>filename;

        ifstream file;
        file.open(filename+".txt");
        if(!file) throw string("Nie udalo sie otworzyc pliku\n");

        T obj;
        string title;
        while(1)
        {
            if(!file && !file.eof())
            {
                throw string("Wczytywanie z pliku zakonczone bledem\n Czy plik na pewno ma poprawne dane?\n");

            }
            else if(file.eof()) break;
            else
            {
                file>>*this;
            }
        }

        file.close();
    }
    catch (string s)
    {
        cout<<s;
    }
    catch (length_error)
    {
        cout<<"wprowadzono za dluga nazwe\n";
    }
    catch (exception)
    {
        cout<<"Wystapil nieznany blad\n";
    }
}



