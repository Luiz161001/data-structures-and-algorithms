#include <iostream>
#include <limits>
#include "LinkedStack.cpp"

template <typename T>
void reverseDisplay(LinkedStack<T> &aStack){
    
}
template <typename T>
void deleteItem(LinkedStack<T> &aStack, const T &givenItem){
}

int main()
{
    LinkedStack<int> aStack;
    int givenItem;

    aStack.push(10);
    aStack.push(20);
    aStack.push(30);
    aStack.push(30);
    aStack.push(40);
    aStack.push(40);
    aStack.push(40);
    aStack.push(50);

    // Stack is *50 40 40 40 30 30 20 10 [* indicates top]

    std::cout << "The size of the stack \"aStack\" is:  " << aStack.size() << std::endl;
    std::cout << "The top of stack \"aStack\" is:  " << aStack.top() << std::endl;
    // TASK 1----------------------------------------------------------------
    // display the elements of stack in reverse order
    //-----------------------------------------------------------------------
    reverseDisplay(aStack); // It should display the elements in this order 10 20 30 30 40 40 40 50

    std::cout << "\nAfter displaying the elements in the reverse order:\n";
    std::cout << "The size of the original stack \"aStack\" is:  " << aStack.size() << std::endl;
    std::cout << "The top of stack \"aStack\" is:  " << aStack.top() << std::endl;

    // TASK 2----------------------------------------------------------------
    // Remove all occurrences of givenItem from aStack as we place them into auxStack in reverse order

    std::cout << "\nNext, going to remove all occurences of a given item from \"aStack\":\n";
    std::cout << "\nEnter the item whose all occurences are to be deleted: ";
    std::cin >> givenItem;
    deleteItem(aStack, givenItem);
    std::cout << "\nThe size of the original stack \"aStack\":  after deleting all occurences of " << givenItem << " are:  " << aStack.size() << std::endl;


    std::cout<<"-------------------------------------\nMy test:\n";
    LinkedStack<int> aStack2(aStack);
    std::cout<<"Using copy constructor\nTop element of orignal stack: "<<aStack.top()<<"\n";
    std::cout<<"Size of orignal stack: "<<aStack.size()<<"\n";

    std::cout<<"Top element of copy stack: "<<aStack2.top()<<"\n";
    std::cout<<"Size of copy stack: "<<aStack2.top()<<"\n";

    std::cout<<"-------------------------------------\nPop of all elements of both stacks:\n";
    std::cout<<"Original Stack:\n";
    while(aStack.size()!=0){
        std::cout<<aStack.top()<<" ";
        aStack.pop();
    }
    std::cout<<"\nCopy Stack:\n";
    while(aStack2.size()!=0){
        std::cout<<aStack2.top()<<" ";
        aStack2.pop();
    }
    std::cout<<"\n";

    std::cout<<"-------------------------------------\nTesting isEmpty()\n";
    std::cout<<"Size of stack: "<<aStack.size()<<"\n";
    std::cout<<"isEmpty: "<<aStack.isEmpty()<<"\n";
    aStack.push(100);
    std::cout<<"Size of stack: "<<aStack.size()<<"\n";
    std::cout<<"isEmpty: "<<aStack.isEmpty()<<"\n";
    return 0;
}
