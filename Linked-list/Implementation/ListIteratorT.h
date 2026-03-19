#pragma once
#include <iterator>
#include <stdexcept>
#include "NodeT.h"

template <class T>
class ListIteratorT{
    private:
        NodeT<T> *currentPtr;
    public:
    //constructors
        //default
        ListIteratorT();
        //parameter
        ListIteratorT(NodeT<T> *curPtr);

    //operations
        //moves to the next node if current pointer is not nullptr
        ListIteratorT<T> operator++();
        //moves to the previous node if current pointer is not nullptr
        ListIteratorT<T> operator--();
        //returns the data if the current pointer is not nullptr
        T &operator*();
        //returns true if the current pointer is different from the parameter current pointer
        bool operator!=(const ListIteratorT<T> &iter) const;
};