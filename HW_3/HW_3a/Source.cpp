// HW_3a
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

// =============================================================================

#include "UnsortedList.h"
#include <iostream>
#include <iomanip>

UnsortedList::UnsortedList() { 
    length = 0; 
}

UnsortedList::~UnsortedList() {}

void UnsortedList::insertItem(int id) {
    if (isFull()) {
        std::cout << "List is full. Cannot insert the number.\n";
    } else {
        numbers[length] = id;
        length++;
    }
}

bool UnsortedList::isFull() const {
    return (length == SIZE);
}

bool UnsortedList::isEmpty() const {
    return (length == 0);
}

void UnsortedList::deleteItem(int id) {
    int location = 0;

    // Linear search for item
    while (location < length && id != numbers[location]) {
        location++;
    }

    if (location < length) { // Item has been found
        // The last item in the list is assigned to numbers[location]
        numbers[location] = numbers[length - 1];
        length--;
    } else { // Item is not in the list
        std::cout << "Id is not in the list.\n";
    }
}

void UnsortedList::displayList() const {
    if (isEmpty()) {
        std::cout << "the list is empty\n";
    } else {
        for (int location = 0; location < length; location++) {
            std::cout << numbers[location] << std::endl;
        }
    }
}

// =============================================================================

#include "UnsortedList.h"
#include <iostream>
using namespace std;

void insertItem(UnsortedList& list, int id);
void deleteItem(UnsortedList& list, int id);
void showMenu();
char getChoice();

int main()
{
    UnsortedList list;
    char choice = ' ';
    int id = 0;

    while (true) {
        showMenu();
        choice = getChoice();

        switch(choice) {
            case 'a':
                cout << "Enter a number: ";
                cin >> id;
                insertItem(list, id);
                break;
            case 'b':
                cout << "Enter the number to be deleted: ";
                cin >> id;
                deleteItem(list, id);
                break;
            case 'q':
                cout << "Quitting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

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

void showMenu()
{
    cout << "a. Insert a number into the list." << endl;
    cout << "b. Delete a number from the list." << endl;
}

char getChoice()
{
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}

// =============================================================================

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
Enter a number: 4
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 5
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 6
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 7
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 8
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 9
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 10
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: a
Enter a number: 11
The list is full - cannot insert the number
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 1
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 2
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 3
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 4
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 5
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 6
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 7
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 8
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 9
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: n
Invalid choice. Please try again.
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 10
a. Insert a number into the list.
b. Delete a number from the list.
Enter your choice: b
Enter the number to be deleted: 11
The list is empty.
a. Insert a number into the list.
b. Delete a number from the list.
*/