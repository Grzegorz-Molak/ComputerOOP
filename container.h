#pragma once
#include "node.h"
#include "iostream"

using namespace std;

template<class T>
class Container
{
public:
    Container() {}
    Container(const Container& c);
    ~Container()
    {
        try
        {
            Node<T>* ptr = begin();
            Node<T>* p_ptr = ptr;
            while(ptr)
            {
                ptr = ptr->next();
                delete ptr;
                setSize(size() - 1);
            }
            if(size() > 0) throw string("Nie udalo sie usunac wszystkich elementow");
        }
        catch (string s)
        {
            cout<<s;
        }

    }

    Container& operator=(const Container& c);
    bool operator==(const Container& c);
    T& operator[](int i);

    friend std::ostream& operator<<(std::ostream &s, Container &c) {
        Node<T>* ptr = c.begin();
        for(int i = 1; i <= c.size(); i++)
        {
            if(!ptr) throw string("Przekroczono zakres tablicy\n");
            cout<<i<<": "<<ptr->value()<<endl;
            ptr = ptr->next();

        }
        return s;
    }
    friend istream & operator>>(istream& s, Container &c)
    {
        s>>c.m_end;
        return s;
    }

    void push_back(T elem);
    void push(int pos, T elem);

    void pop_back();
    void pop(int pos);

    void swap(int s1, int s2);
    void moveToEnd(int n);

    void save();
    void read();



    Node<T> *begin() const {return m_begin;}
    void setBegin(Node<T> *begin) { m_begin = begin;}

    Node<T> *end() const { return m_end;}
    void setEnd(Node<T> *end) { m_end = end;}

    void setSize(int size) {m_size = size;}
    int size() { return m_size;}

private:
    Node<T>* at(int pos);
    Node<T>* m_begin = nullptr;
    Node<T>* m_end = nullptr;
    int m_size = 0;

};


// ***********************************************

template<class T>
Node<T>* Container<T>::at(int pos)
{
    Node<T>* ptr;
    if(pos < size()/2)
    {
        ptr = begin();
        for(int i = 1; i < pos; i++)
        {
            if(ptr->next() == nullptr && i < pos )
            {
                throw string("Wystapila luka w kontenerze");
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
                throw string("Wystapila luka w kontenerze");
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
                if(!new_node) throw string("Blad alokowania pamieci");
                ptr->setPrevious(new_node);
                if(new_node->previous()) (new_node->previous())->setNext(new_node);
                else setBegin(new_node);
                setSize(size()+1);
            }
            catch (string s)
            {
                cout<<s;
            }
        }
        else if(pos == size()+1)
        {
            Node<T>* former_end = end();
            Node<T>* new_end = new Node<T>(elem, former_end);
            if(!new_end) throw string("Blad alokowania pamieci");
            setEnd(new_end);
            former_end->setNext(new_end);
            setSize(size()+1);
        }
        else
        {
            throw string("Nie mozna utworzyc elementu o takim indeksie, zakres to <1,"+to_string(size()+1)+">\n");
        }
    }
    catch(string s)
    {
        cout<<s;
    }
}

template<class T>
void Container<T>::pop(int pos)
{
    try
    {
        if(pos > size())
        {
            throw string("Nie mozna utworzyc elementu o takim indeksie, zakres to <1,"+to_string(size())+">\n");
        }
        else if(size() == 1)
        {
            delete begin();
            setBegin(nullptr);
            setEnd(nullptr);
            setSize(size()-1);

        }
        else if(pos == 0)
        {
            Node<T>* ptr = begin();
            if(!(begin()->next())) throw string("Wystapila luka w kontenerze");
            (begin()->next())->setPrevious(nullptr);
            delete ptr;
            setSize(size()-1);
        }
        else if(pos == size())
        {
            Node<T>* ptr = end();
            if(!(end()->previous())) throw string("Wystapila luka w kontenerze");
            (end()->previous())->setNext(nullptr);
            setSize(size()-1);
        }
        else
        {
            Node<T>*ptr = at(pos);

            if(!(ptr->previous())) throw string("Wystapila luka w kontenerze");
            (ptr->previous())->setNext(ptr->next());

            if(!ptr->next()) throw string("Wystapila luka w kontenerze");
            (ptr->next())->setPrevious(ptr->previous());

            delete ptr;
            setSize(size()-1);
        }
    }
    catch(string s)
    {
        cout<<s;
    }
}

template<class T>
void Container<T>::pop_back()
{
    pop(size());
}



