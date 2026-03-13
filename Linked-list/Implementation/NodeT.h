#pragma once

template<class T>
class NodeT{
    public:
        T item;
        NodeT<T> *next;
        NodeT<T> *prev;

    //contructors
        //default
        NodeT();
        //parameters
        NodeT(T item);
        NodeT(T itm, NodeT<T>* nxt, NodeT<T>* prv);  
};