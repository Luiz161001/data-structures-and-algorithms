#include "NodeT.cpp"
#include "ListIteratorT.cpp"

template<typename T>
class ListT{
    private:
        NodeT<T> *headPtr;
        NodeT<T> *tailPtr;
    public:
    //constructors
        //default
        ListT();
        //parameter
        ListT(const ListT &list);
        //destructor
        ~ListT();

    //displays
        //display in ascending order
        void displayAscending();
        //display in descending order
        void displayDescending();
        //display only one specific item if the index is valid
        void displayOne(int idx);

    //search specific item
        bool searchItem(const T &data) const;

    //inserts
        //insert in the right position
            bool insert(const T &data, int pos);
        //insert newEntry in the begining of the list
            void insertBegin(const T &newEntry);
        //insert newEntry in the end of the list
            void insertEnd(const T &newEntry);

    //removes
        //remove the 1st item
        T removeBegin();
        //remove the last item
        T removeEnd();
        //remove specific item if it exists
        T remove(const T &data);

    //returns true if list is empty
        bool isEmpty() const;
    
    //return current size of the list
        int getCurrentSize() const;

    //copy the list
        ListT<T>& operator=(const ListT &list);

    //iterators
        //set the begin of the list
        ListIteratorT<T> begin() const;
        //set the end of the list
        ListIteratorT<T> end() const;
};      