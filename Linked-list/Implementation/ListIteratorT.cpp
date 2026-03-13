#include "ListIteratorT.h"

template <class T> 
ListIteratorT<T>::ListIteratorT() : currentPtr(nullptr){};

template <class T>
ListIteratorT<T>::ListIteratorT(NodeT<T> *curPtr) : currentPtr(curPtr){};

template <class T>
ListIteratorT<T> ListIteratorT<T>::operator++(){
    if(currentPtr)
        currentPtr=currentPtr->next;
    return currentPtr;
}

template <class T> 
T &ListIteratorT<T>::operator*(){
    if(currentPtr)
        return currentPtr->item;
    throw std::out_of_range("Dereferencing an invalid operator");
}

template <class T>
bool ListIteratorT<T>::operator!=(const ListIteratorT<T> &input) const {
    return !(currentPtr==input.currentPtr);
}
