#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <iostream>

using namespace std;

//array size is 10
const int SIZE = 10;

class UnsortedList {

private: 
    int length;
    int numbers[SIZE];

public:
    UnsortedList();
    ~UnsortedList();

    //inserts and deletes item to main
    void insertItem(int id);
    void deleteItem(int id);

    //check if list is full
    bool isFull()const;

    //checks if list is empty
    bool isEmpty()const;
    void deleteItem()const;
    void displayList() const;
};

#endif