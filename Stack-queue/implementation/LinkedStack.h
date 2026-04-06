#pragma once
#include "NodeT.cpp"

template <typename T>
class LinkedStack{
public:
    LinkedStack();                          // constructor
    LinkedStack(LinkedStack &aStack); // copy constructor

    int size() const;        // returns the number of elements in the stack
    bool isEmpty() const;    // returns true if stack is empty, false otherwise
    const T &top() const;    // returns a copy of the top of the stack if stack is not empty, otherwise throws an exception or prints an error message
    void push(const T &ele); // adds a new item to the top of the stack
    void pop();              // removes the top of the stack if it is not empty, otherwise throws an exception or prints an error message
    ~LinkedStack();          // destructor

private:
    NodeT<T> *topPtr; // pointer to top of stack
    int itemCount;    // number of elements
};