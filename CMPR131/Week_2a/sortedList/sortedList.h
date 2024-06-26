#pragma once
#include <iostream>
#include <string>
//#include <iomanip>
using namespace std;

const int SIZE = 100;

class SortedList
{
    private:
    int length;
    string name[SIZE];

    public:
    //constructor
    SortedList();
    //destructor
    ~SortedList();

    //Functions
    //insert item at the end of the array
    void insertItem(string name);
    //delete item at the end of the array
    void deleteItem(string name);
    //return true if full
    bool isFull()const;
    //return true if empty
    bool isEmpty()const;
    //???
    int binarySearch(string name);
    //???
    int linearSearch(string name);
    //
    void displayList()const;
};
