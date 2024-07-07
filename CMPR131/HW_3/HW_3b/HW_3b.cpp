// attached: HW_3(a,b)
// File: HW_3b.cpp
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
//  but this time sorted
// =============================================================================
// =============================================================================





// ==== SortedList.h ============================================================
// initialized SortedList with functions and max array size of 1000
// =============================================================================

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

class SortedList {
public:
    SortedList();
    void insertItem(int id);
    void deleteItem(int id);
    bool isEmpty() const;
    bool isFull() const;
    bool findItem(int id) const;
    void displayList() const;

private:
    static const int MAX_ITEMS = 100;
    int items[MAX_ITEMS];
    int length;
    int binarySearch(int id) const;
};

#endif // SORTEDLIST_H

// =============================================================================





// === SortedList.cpp ==============================================================
// define functions
// =============================================================================

#include "SortedList.h"
#include <iostream>
using namespace std;

// initialize sorted list
SortedList::SortedList() : length(0) {}
// =============================================================================





// == InsertItem ================================================================
// 
// =============================================================================

void SortedList::insertItem(int id) {

    //checks if too full
    if (isFull()) {
        cout << "The list is full – cannot insert the number." << endl;
        return;
    }

    // checks position
    int pos = 0;

    // if position is less than length, than continue
    while (pos < length && items[pos] < id) {
        pos++;
    }

    // put item in the position before
    for (int i = length; i > pos; i--) {
        items[i] = items[i - 1];
    }

    // insert item at position and increase length
    items[pos] = id;
    length++;
}
// =============================================================================





// ===== deleteItem ==============================================================
// deletes item in array
// =============================================================================

void SortedList::deleteItem(int id) {
    // base case if empty, than cannot delete
    if (isEmpty()) {
        cout << "The list is empty. Cannot delete item." << endl;
        return;
    }

    // call binary search
    int pos = binarySearch(id);
    if (pos == -1) {
        cout << "Item is not in the list." << endl;
        return;
    }

    for (int i = pos; i < length - 1; i++) {
        items[i] = items[i + 1];
    }

    length--;
    cout << "Item has been deleted." << endl;
}
// =============================================================================





// ===isEmpty ================================================================
// checks if empty
// =============================================================================

bool SortedList::isEmpty() const {
    return length == 0;
}

// =============================================================================





// ==== isFull ===========================================================
// checks ifFull
// =============================================================================

bool SortedList::isFull() const {
    return length == MAX_ITEMS;
}
// =============================================================================






// ===== findItem ===========================================================
// finds item using binary search
// =============================================================================

bool SortedList::findItem(int id) const {
    return binarySearch(id) != -1;
}

// =============================================================================






// ==== displayList =============================================================
//  displays information in array
// =============================================================================

void SortedList::displayList() const {
    for (int i = 0; i < length; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

// =============================================================================





// === binarySearch =============================================================
// works by checking at midpoint over and over again
// =============================================================================

int SortedList::binarySearch(int id) const {
    int left = 0;
    int right = length - 1;

    // checks the midpoint of the sides.
    while (left <= right) {
        int mid = (left + right) / 2;

        // if mid point = id then return it
        if (items[mid] == id) {
            return mid;
        } 
        
        // checks if mid is less than id
        else if (items[mid] < id) {
            left = mid + 1;
        } 
        
        // continues on the right side of the array
        else {
            right = mid - 1;
        }
    }

    return -1;
}

// =============================================================================





// === main.cpp ==============================================================
//
// =============================================================================

#include "SortedList.h"
#include <iostream>
using namespace std;

//function prototype
void insertItem(SortedList& list, int id);
void deleteItem(SortedList& list, int id);
void showMenu();
char getChoice();

int main() {

    //declaring variables
    SortedList list;
    char choice = ' ';
    int id = 0;

    // continues until false
    while (true) {
        showMenu();
        choice = getChoice();

        // switch case to decide what to do
        switch (choice) {
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

        cout << "\nDisplaying the List:\n";
        list.displayList();
    }

    return 0;
} // end of main
// =============================================================================







// === InsertItem ===========================================================
// 
// =============================================================================

void insertItem(SortedList& list, int id) {
    if (!list.isFull()) {
        list.insertItem(id);
        cout << "Item inserted." << endl;
    } else {
        cout << "The list is full – cannot insert the number." << endl;
    }
}
// =============================================================================





// ==== deleteItem =============================================================
// deletes item using id
// =============================================================================

void deleteItem(SortedList& list, int id) {
    if (!list.isEmpty()) {
        if (list.findItem(id)) {
            list.deleteItem(id);
        } else {
            cout << "Item is not in the list." << endl;
        }
    } else {
        cout << "The list is empty." << endl;
    }
}
// =============================================================================




// == showMenu ==================================================================
// shows menu
// =============================================================================

void showMenu() {
    cout << "\nMenu:" << endl;
    cout << "a. Insert a number into the list." << endl;
    cout << "b. Delete a number from the list." << endl;
    cout << "q. Quit the program." << endl;
}
// =============================================================================




// === getChoice ===============================================================
// gets choice from user
// =============================================================================

char getChoice() {
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}

// =============================================================================






// == Output =================================================================

/*
Menu:
a. Insert a number into the list.
b. Delete a number from the list.
q. Quit the program.
Enter your choice: a 
Enter a number: 1
Item inserted.

Displaying the List:
1 

Menu:
a. Insert a number into the list.
b. Delete a number from the list.
q. Quit the program.
Enter your choice: b
Enter the number to be deleted: 1
Item has been deleted.

Displaying the List:


Menu:
a. Insert a number into the list.
b. Delete a number from the list.
q. Quit the program.
Enter your choice: q
Quitting the program.
*/
// =============================================================================
