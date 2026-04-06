#include "NodeT.h"

// default constructor
template <class T>
NodeT<T>::NodeT() : next(nullptr){}

// parameterized constructor
template <class T>
NodeT<T>::NodeT(const T &item, NodeT<T> *next) : item(item), next(next){}