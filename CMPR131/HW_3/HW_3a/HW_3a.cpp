// Attached: HW_3(a,b)
// File: Hw_3a.cpp
// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Add or Delete
// =============================================================================
// Description: This program allows you to add or delete items in an array of 10
//
// =============================================================================
// =============================================================================





// === UnsortedList.h ===========================================================
// List that holds 10 integers, initialized empty and numbers can be inserted or 
// deleted from the list
// =============================================================================

#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <iostream>

using namespace std;

//array size is 10
const int SIZE = 10;

class UnsortedList {

private: 
    // member variables for length and size of array
    int length;
    int numbers[SIZE];

public:
    //constructor, destructor
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

}; // end of Unsorted list.h

#endif

// =============================================================================





// ==== UnsortedList.cpp  =======================================================
// implements the methods
// =============================================================================

#include "UnsortedList.h"
#include <iostream>
#include <iomanip>

// initialize to size zero
UnsortedList::UnsortedList() { 
    length = 0; 
}

// destructor
UnsortedList::~UnsortedList() {}






// ==== insertItem =============================================================
// inserts item into the array
// =============================================================================

void UnsortedList::insertItem(int id) 
{
    // checks if the array is full before adding
    if (isFull()) {
        std::cout << "List is full. Cannot insert the number.\n";
    } 

    // add the item in
    else {
        numbers[length] = id;
        length++;
    }
}
// =============================================================================





// ==== isFull ==============================================================
// checks if array is full
// =============================================================================

bool UnsortedList::isFull() const {
    return (length == SIZE);
}
// =============================================================================





// === isEmpty ====================================================================
// checks if array is empty
// =============================================================================

bool UnsortedList::isEmpty() const {
    return (length == 0);
}
// =============================================================================





// ==== deleteItem ====================================================================
// deletes item from array
// =============================================================================

void UnsortedList::deleteItem(int id) {

    // starts at location 0
    int location = 0;

    // Linear search for item (searching from beg to end)
    while (location < length && id != numbers[location]) {
        location++;
    }

    
    if (location < length) { // Item has been found

        // The last item in the list is assigned to numbers[location]
        numbers[location] = numbers[length - 1];
        length--;
    } 
    
    else { // Item is not in the list
        std::cout << "Id is not in the list.\n";
    }
}
// =============================================================================





// ==== displayList =================================================================
// displays entire list
// =============================================================================

void UnsortedList::displayList() const {

    // checks if empty
    if (isEmpty()) {
        std::cout << "the list is empty\n";
    } 
    
    else {
        // loops through array and prints
        for (int location = 0; location < length; location++) {
            std::cout << numbers[location] << std::endl;
        }
    }
} 
// =============================================================================






// end of Unsorted.cpp
// =============================================================================





// == HW_3a.cpp ================================================================
//
// =============================================================================

#include "UnsortedList.h"
#include <iostream>
using namespace std;

// function prototype
void insertItem(UnsortedList& list, int id);
void deleteItem(UnsortedList& list, int id);
void showMenu();
char getChoice();

int main()
{
    //initialize variables
    UnsortedList list;
    char choice = ' ';
    int id = 0;

    // checks if case is still true
    while (true) {
        showMenu();
        choice = getChoice();

        // switch to decide inputs from user
        switch(choice) {
            case 'a':
                //prompt for number
                cout << "Enter a number: ";
                cin >> id;
                insertItem(list, id);
                break;

            case 'b':
                //prompt for delete
                cout << "Enter the number to be deleted: ";
                cin >> id;
                deleteItem(list, id);
                break;

            case 'q':
                //quit program
                cout << "Quitting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
} // end of main function

// =============================================================================






// === InsertItem ============================================================
// inserts item information
// =============================================================================

void insertItem(UnsortedList& list, int id)
{
    if(!list.isFull())
    {
        list.insertItem(id);
    }
    else {
        cout << "The list is full - cannot insert the number" << endl;
    }
}
// =============================================================================





// === deleteItem ============================================================
// deletes item at id
// =============================================================================
void deleteItem(UnsortedList& list, int id)
{
    if (!list.isEmpty())
    {
        list.deleteItem(id);
    }
    else
    {
        cout << "The list is empty.\n\n";
    }
}
// =============================================================================






// === showMenu ============================================================
// shows Menu 
// =============================================================================
void showMenu()
{
    cout << "a. Insert a number into the list." << endl;
    cout << "b. Delete a number from the list." << endl;
}
// =============================================================================





// === getChoice ============================================================
// getschoice from user
// ===========================================================================
char getChoice()
{
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}
// =============================================================================







// == Output =================================================================

/*
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 1

a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: 2
Invalid choice. Please try again.

a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 2
Id is not in the list.

a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 2

a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 3

a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a

*/
// =============================================================================