#pragma once
#include "node.h"
#include "iostream"

using namespace std;

template<class T>
class Container
{
public:
    Container();
    Container(const Container& c);
    ~Container();

    Container& operator=(const Container& c);
    bool operator==(const Container& c);

    friend ostream & operator<<(ostream& s, const Container<T>& c);
    friend istream & operator>>(istream& s, Container<T>& c);

    void push_back(T elem);
    void push(int pos, T elem);

    void pop_back();
    void pop(int pos);

    void swap(int s1, int s2);

    int size();

    void save();
    void read();

private:
    Node<T>* m_begin;
    Node<T>* m_end;
    size_t m_size;

};

