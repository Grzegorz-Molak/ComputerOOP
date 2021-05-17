#pragma once

template<class T>
class Node
{
    Node();
    ~Node();

    T value;
    Node* previous;
    Node* next;

};
