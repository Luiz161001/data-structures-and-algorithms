#include "ListT.h"
#include <iostream>

//constructors
//default
template <class T>
ListT<T>::ListT() : headPtr(nullptr), tailPtr(nullptr){}

//parameter
template <class T>
ListT<T>::ListT(const ListT &list){}
//destructor
template <class T>
ListT<T>::~ListT(){

}

//--------------------------------------------
// inserts
template <class T>
void ListT<T>::insert(const T &data, int pos){
    NodeT<T> *newNode = new NodeT(data);

    if(headPtr==nullptr) 
        headPtr=tailPtr=newNode;
    else{
        NodeT<T> *tmp = headPtr; 
        //insert starting from the beginning (has better ways of doing it, do it later)
        while(tmp && pos>0){
            pos--;
            tmp=tmp->next;
        }
        newNode->prev=tmp;
        newNode->next= tmp->next;
        tmp->next=newNode;
    }   
}

template <class T>
void ListT<T>::insertBegin(const T &newEntry){
    NodeT<T> *newNode = new NodeT(newEntry,headPtr,nullptr);
    if(headPtr==nullptr)
        headPtr=tailPtr=newNode;
    else{
        headPtr->prev=newNode;
        headPtr=newNode;
    }
}

template <class T>
void ListT<T>::insertEnd(const T &newEntry){
    NodeT<T> *newNode = new NodeT(newEntry,nullptr,tailPtr);
    if(headPtr==nullptr)
        headPtr=tailPtr=newNode;
    else{
        tailPtr->next=newNode;
        tailPtr=newNode;
    }
}

// template <class T>
// void ListT<T>::sortedInsert(const T &data){

// }


//--------------------------------------------
//displays
template <class T>
void ListT<T>::displayAscending(){
    NodeT<T> *tmp = headPtr;
    while(tmp){
        cout<<tmp->item<<" ";
        tmp=tmp->next;
    }
    cout<<"\n";
}

template <class T>
void ListT<T>::displayDescending(){
    NodeT<T> *tmp = tailPtr;
    while(tmp){
        cout<<tmp->item<<" ";
        tmp=tmp->prev
    }
    cout<<"\n";
}

template <class T>
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
template <class T>
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
template <class T>
bool ListT<T>::isEmpty(){
    return headPtr==nullptr;
}
    
template <class T>
int ListT<T>::getCurrentSize(){
    int size = 0;
    NodeT<T> tmp = headPtr;
    while(tmp){
        size++;
        tmp=tmp->next;
    }
    return size;
}