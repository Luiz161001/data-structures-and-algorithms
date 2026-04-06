#pragma once
template <class T>
class NodeT
{
public:
    NodeT();                              // default constructor
    NodeT(const T &item, NodeT<T> *next); // parameterized constructor

    T item;         // A data item
    NodeT<T> *next; // A pointer to next node
};
