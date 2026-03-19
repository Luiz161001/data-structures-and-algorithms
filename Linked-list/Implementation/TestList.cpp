#include "ListT.cpp"
#include <iostream>

int main(){
    ListT<int> ll;
    ll.insertBegin(4);
    ll.insertBegin(2);
    ll.insertBegin(7);
    ll.insertBegin(20);
    ll.insertBegin(5);
    ll.insertBegin(100);

    std::cout<<"Using constructor:\n";
    std::cout<<"Size: "<<ll.getCurrentSize() << "\n";
    std::cout<<"Items on the list:\n";
    ListIteratorT<int> itr;

    for(itr=ll.begin(); itr!=ll.end(); ++itr){
        std::cout<<*itr<< " ";
    }

    std::cout<<"\n--------------------------\n";
    std::cout<<"Using copy constructor:\n";

    ListT<int> ll2(ll);

    std::cout<<"Size: "<<ll.getCurrentSize() << "\n";
    std::cout<<"Items on the list:\n";
    for(itr=ll2.begin(); itr!=ll2.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\n--------------------------\n";
    std::cout<<"Enter an item to be searched: ";
    int item;
    std::cin>>item;
    if(ll.searchItem(item))
        std::cout<<"\n"<<item<<" is on the list!!\n";
    else
        std::cout << "\n"<<item<<" is not on the list!!\n";

    std::cout<<"--------------------------\n";
    std::cout<<"Items on the list before removing:\n";
    for(itr=ll.begin(); itr!=ll.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\n\nRemoving items from the list:\n\n";
    std::cout<<"Removing first item: "<<ll.remove(100)<<"\n";
    std::cout<<"Removing last item: "<<ll.remove(4)<<"\n";
    std::cout<<"Removing item in the middle: "<<ll.remove(20)<<"\n";

    std::cout<<"\nItems on the list after removing:\n";
    for(itr=ll.begin(); itr!=ll.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\nItems on the second list after removing items from first list:\n";
    for(itr=ll2.begin(); itr!=ll2.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\n--------------------------\n";
    std::cout<<"Size of list 1: "<<ll.getCurrentSize()<<"\nSize of list 2: "<<ll2.getCurrentSize();
    std::cout<<"\n--------------------------\n";

    std::cout<<"Creating a third list from the list that had deleted items:\n";

    ListT<int> ll3(ll);
    std::cout<<"\nItems on the first:\n";
    for(itr=ll.begin(); itr!=ll.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\nItems on the third:\n";
    for(itr=ll3.begin(); itr!=ll3.end(); ++itr){
        std::cout<<*itr<<" ";
    }
    std::cout<<"\n--------------------------\n";
    return 0;
}