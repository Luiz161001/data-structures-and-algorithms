#include "LinkedStack.h"
#include <iostream>
#include <stdexcept>

template<typename T>
LinkedStack<T>::LinkedStack():topPtr(nullptr),itemCount(0){}

template<typename T>
LinkedStack<T>::LinkedStack(LinkedStack &aStack){
    topPtr=nullptr;
    itemCount=aStack.itemCount;
    LinkedStack<T> reversedCopy;
    while (aStack.topPtr){
        reversedCopy.(aStack.top);
        aStack.pop();
    }   
    while (aStack.topPtr){
        push(reversedCopy.top);
        aStack.push(tmp.top());
        reversedCopy.pop();
    }   
} 

template<typename T>
int LinkedStack<T>::size() const{
    return itemCount;
}  

template<typename T>
bool LinkedStack<T>::isEmpty() const{
    return topPtr==nullptr;
}

template<typename T>
const T &LinkedStack<T>::top() const{
    if(topPtr){
        return topPtr->item;
    }
    throw std::invalid_argument("Stack is empty!"); 
}

template<typename T>
void LinkedStack<T>::push(const T &ele){
    NodeT<T> *tmp=new NodeT<T>(ele, topPtr);
    topPtr=tmp;
    itemCount++;
}

template<typename T>
void LinkedStack<T>::pop(){
    if(topPtr){
        NodeT<T> *tmp=topPtr->next;
        delete topPtr;
        topPtr=tmp;
        itemCount--;
        return;
    }
    throw std::invalid_argument("Stack is empty!");
}  

template<typename T>
LinkedStack<T>::~LinkedStack(){
    while(topPtr)
        pop();
}

template<typename T>
void LinkedStack<T>::reverseDisplay(){
    LinkedStack<T> copy;
    while(topPtr){
        copy.push(top());
        pop();
    }
    while(copy.topPtr){
        std::cout<<top()<<" ";
        push(top());
        copy.pop();
    }
    std::cout<<"\n";
}

template<typename T>
void LinkedStack<T>::deleteItem(const T &givenItem){
    LinkedStack<T> copy;
    while(topPtr){
        if(top()==givenItem) continue;
        copy.push(top());
        pop();
    }
    if(copy.size()==size()){
        std::cout<<"Item is not in the stack!\n";
    }
    while(copy.topPtr){
        push(top());
        copy.pop();
    }
}