#pragma once

template<class T>
class Node
{
public:
    Node() {}
    Node(T elem) {setValue(elem);}
    Node(T elem, Node<T>* previous) {setValue(elem); setPrevious(previous);}
    Node(T elem, Node<T>* previous, Node<T>* next) {setValue(elem); setPrevious(previous); setNext(next);}
    ~Node() {}

    T value() const {return m_value;}
    void setValue(const T &value) {m_value = value; }

    Node *previous() const {return m_previous;}
    void setPrevious(Node *previous) {m_previous = previous;}

    Node *next() const {return m_next;}
    void setNext(Node *next) {m_next = next;}

private:
    T m_value;
    Node* m_previous = nullptr;
    Node* m_next = nullptr;

};

