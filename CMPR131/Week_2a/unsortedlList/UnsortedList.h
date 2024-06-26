#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <iostream>

using namespace std;

const int SIZE = 100;

class UnsortedList {

private: 
    int length;
    int idNumbers[SIZE];

public:
    UnsortedList();
    ~UnsortedList();

    void insertItem(int id);
    void deleteItem(int id);

   bool isFull()const;
   bool isEmpty()const;

   void deleteItem()const;

};

#endif
