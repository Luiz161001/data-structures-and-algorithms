#include "ListT.h"
#include <iostream>

//constructors
//default
template <typename T>
ListT<T>::ListT() : headPtr(nullptr), tailPtr(nullptr){}

//parameter
// template <typename T>
// ListT<T>::ListT(const ListT &list){}

//destructor
// template <typename T>
// ListT<T>::~ListT(){

// }

//--------------------------------------------
// inserts
template <typename T>
bool ListT<T>::insert(const T &data, int pos){
    if(pos < 0) return false;

    if(pos==0){
        NodeT<T> *newNode = new NodeT<T>(data, nullptr, headPtr);
        if(headPtr)
            headPtr->prev = newNode;
        headPtr = newNode;
        return true;
    }

    NodeT<T> *tmp = headPtr;
    int index = 0;

    while(tmp && index < pos - 1){
        tmp=tmp->next;
        index++;
    }

    if(tmp == nullptr) return false;

    NodeT<T> *newNode = new NodeT<T>(data, tmp, tmp->next);

    if(tmp->next) 
        tmp->next->prev = newNode;

    tmp->next = newNode;
    return true;
}

template <typename T>
void ListT<T>::insertBegin(const T &newEntry){
    NodeT<T> *newNode = new NodeT<T>(newEntry,headPtr,nullptr);
    if(headPtr==nullptr)
        headPtr=tailPtr=newNode;
    else{
        headPtr->prev=newNode;
        headPtr=newNode;
    }
}

template <typename T>
void ListT<T>::insertEnd(const T &newEntry){
    NodeT<T> *newNode = new NodeT<T>(newEntry,nullptr,tailPtr);
    if(headPtr==nullptr)
        headPtr=tailPtr=newNode;
    else{
        tailPtr->next=newNode;
        tailPtr=newNode;
    }
}

// template <typename T>
// void ListT<T>::sortedInsert(const T &data){

// }


//--------------------------------------------
//removes
// template <typename T>
// T ListT<T>::removeBegin(){
//     if(isEmpty())
//         throw std::invalid_argument("List is empty!");
    
// }

// template <typename T>
// T ListT<T>::removeEnd(){

// }

// template <typename T>
// T remove(const T &data);


//--------------------------------------------
//displays
template <typename T>
void ListT<T>::displayAscending(){
    NodeT<T> *tmp = headPtr;
    while(tmp){
        cout<<tmp->item<<" ";
        tmp=tmp->next;
    }
    cout<<"\n";
}

template <typename T>
void ListT<T>::displayDescending(){
    NodeT<T> *tmp = tailPtr;
    while(tmp){
        cout<<tmp->item<<" ";
        tmp=tmp->prev
    }
    cout<<"\n";
}

template <typename T>
void ListT<T>::displayOne(int idx){
    if(idx>getCurrentSize() || idx<=0)
        throw std::invalid_argument("Index out of range!");
    NodeT<T> *tmp = headPtr;
    for(int i=0; i<idx; i++)
        tmp=tmp->next;
    cout << tmp->item < endl;
}


//--------------------------------------------
//searches
template <typename T>
bool ListT<T>::searchItem(const T &data) const{
    NodeT<T> tmp = headPtr;
    while(tmp){
        if(data==tmp.item) return true;
        tmp=tmp->next;
    }
    return false;
}

//--------------------------------------------
//Utility Functions
template <typename T>
bool ListT<T>::isEmpty(){
    return headPtr==nullptr;
}
    
template <typename T>
int ListT<T>::getCurrentSize(){
    int size = 0;
    NodeT<T> tmp = headPtr;
    while(tmp){
        size++;
        tmp=tmp->next;
    }
    return size;
}