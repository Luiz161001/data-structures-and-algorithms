#include "NodeT.h"

template<class T>
NodeT<T>::NodeT() : next(nullptr), prev(nullptr){}

template<class T>
NodeT<T>::NodeT(T itm) : item(itm), next(nullptr), prev(nullptr){}

template<class T>
NodeT<T>::NodeT(T itm, NodeT<T>* nxt, NodeT<T>* prv) : item(itm), next(nxt), prev(prv){}
