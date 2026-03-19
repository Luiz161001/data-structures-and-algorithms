#include "ListT.h"
#include <iostream>

//constructors
//default
template <typename T>
ListT<T>::ListT() : headPtr(nullptr), tailPtr(nullptr){}

//parameter
template <typename T>
ListT<T>::ListT(const ListT &list){
    headPtr=nullptr;
    NodeT<T> *tmp = list.headPtr;
    while(tmp){
        insertEnd(tmp->item);
        tmp=tmp->next;
    }
}

//destructor
template <typename T>
ListT<T>::~ListT(){
    while (headPtr)
        removeBegin();
    std::cout<<"Destructor activated\n";
}

//--------------------------------------------
// inserts
template <typename T>
bool ListT<T>::insert(const T &data, int pos){
    if(pos < 0) return false;

    if(pos==0){
        NodeT<T> *newNode = new NodeT<T>(data, headPtr, nullptr);
        if(headPtr)
            headPtr->prev=newNode;
        else  
            tailPtr=newNode;
        headPtr=newNode;
        return true;
    }

    NodeT<T> *tmp=headPtr;
    int index=0;

    while(tmp && index < pos - 1){
        tmp=tmp->next;
        index++;
    }

    if(tmp==nullptr) return false;

    NodeT<T> *newNode=new NodeT<T>(data, tmp->next, tmp);

    if(tmp->next) 
        tmp->next->prev=newNode;
    else    
        tailPtr=newNode;
    tmp->next=newNode;
    return true;
}

template <typename T>
void ListT<T>::insertBegin(const T &newEntry){
    NodeT<T> *newNode = new NodeT<T>(newEntry,headPtr,nullptr);
    if(isEmpty())
        headPtr=tailPtr=newNode;
    else{
        headPtr->prev=newNode;
        headPtr=newNode;
    }
}

template <typename T>
void ListT<T>::insertEnd(const T &newEntry){
    NodeT<T> *newNode = new NodeT<T>(newEntry,nullptr,tailPtr);
    if(isEmpty())
        headPtr=tailPtr=newNode;
    else{
        tailPtr->next=newNode;
        tailPtr=newNode;
    }
}

//--------------------------------------------
//removes
template <typename T>
T ListT<T>::removeBegin(){
    if(isEmpty())
        throw std::invalid_argument("List is empty!");
    
    T item = headPtr->item;
    if(headPtr==tailPtr){
        delete headPtr;
        headPtr=tailPtr=nullptr;
        return item;
    }

    NodeT<T> *tmp = headPtr;
    headPtr=headPtr->next;
    headPtr->prev=nullptr;
    delete tmp;
    tmp = nullptr;
    return item;
}

template <typename T>
T ListT<T>::removeEnd(){
    if(isEmpty())
        throw std::invalid_argument("List is empty!");

    T item = tailPtr->item; 
    
    if(headPtr==tailPtr){
        delete headPtr;
        headPtr=tailPtr=nullptr;
        return item;
    }

    NodeT<T> *tmp = tailPtr;
    tailPtr=tailPtr->prev;
    tailPtr->next=nullptr;
    delete tmp;
    tmp = nullptr;
    return item;
}

template <typename T>
T ListT<T>::remove(const T &data){
    if(isEmpty())
        throw std::invalid_argument("List is empty!");

    NodeT<T> *tmp = headPtr;
    while(tmp){
        if(tmp->item==data){
            if(tmp==headPtr) return removeBegin();
            if(tmp==tailPtr) return removeEnd();
            

            T item = tmp->item;
            //the next element of the tmp->prev becomes the tmp->next
            tmp->prev->next=tmp->next;
            //the previous element of the tmp->next becomes the tmp->prev
            tmp->next->prev=tmp->prev;

            delete tmp;
            return item;
        }
        tmp=tmp->next;
    }
    throw std::invalid_argument("Item is not on the list!");
}


//--------------------------------------------
//displays
template <typename T>
void ListT<T>::displayAscending(){
    NodeT<T> *tmp = headPtr;
    while(tmp){
        std::cout<<tmp->item<<" ";
        tmp=tmp->next;
    }
    std::cout<<"\n";
}

template <typename T>
void ListT<T>::displayDescending(){
    NodeT<T> *tmp = tailPtr;
    while(tmp){
        std::cout<<tmp->item<<" ";
        tmp=tmp->prev;
    }
    std::cout<<"\n";
}

template <typename T>
void ListT<T>::displayOne(int idx){
    if(idx>getCurrentSize() || idx<=0)
        throw std::invalid_argument("Index out of range!");
    NodeT<T> *tmp = headPtr;
    for(int i=1; i<idx; i++)
        tmp=tmp->next;
    std::cout << tmp->item << std::endl;
}


//--------------------------------------------
//searches
template <typename T>
bool ListT<T>::searchItem(const T &data) const{
    NodeT<T> *tmp = headPtr;
    while(tmp){
        if(data==tmp->item) return true;
        tmp=tmp->next;
    }
    return false;
}

//--------------------------------------------
//Utility Functions
template <typename T>
bool ListT<T>::isEmpty() const{
    return headPtr==nullptr;
}
    
template <typename T>
int ListT<T>::getCurrentSize() const{
    int size = 0;
    NodeT<T> *tmp = headPtr;
    while(tmp){
        size++;
        tmp=tmp->next;
    }
    return size;
}

//--------------------------------------------
//Operators
template <typename T>
ListT<T>& ListT<T>::operator=(const ListT &list){
    if (this == &list) return *this;

    while (!isEmpty())
        removeBegin();
    
    headPtr=tailPtr=nullptr;
    NodeT<T> *tmp = list.headPtr;
    while (tmp){
        insertEnd(tmp->item);
        tmp=tmp->next;
    }
    return *this;
}

//--------------------------------------------
//Iterators 
template <typename T>
ListIteratorT<T> ListT<T>::begin() const {
    return ListIteratorT<T>(headPtr);
}

template <typename T>
ListIteratorT<T> ListT<T>::end() const {
    return ListIteratorT<T>(nullptr);
}