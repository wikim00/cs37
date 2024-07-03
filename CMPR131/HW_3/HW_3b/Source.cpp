// HW_3b
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


#include "SortedList.h"
#include <iostream>
using namespace std;

SortedList::SortedList() : length(0) {}

void SortedList::insertItem(int id) {
    if (isFull()) {
        cout << "The list is full – cannot insert the number." << endl;
        return;
    }

    int pos = 0;
    while (pos < length && items[pos] < id) {
        pos++;
    }

    for (int i = length; i > pos; i--) {
        items[i] = items[i - 1];
    }

    items[pos] = id;
    length++;
}

void SortedList::deleteItem(int id) {
    if (isEmpty()) {
        cout << "The list is empty. Cannot delete item." << endl;
        return;
    }

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

bool SortedList::isEmpty() const {
    return length == 0;
}

bool SortedList::isFull() const {
    return length == MAX_ITEMS;
}

bool SortedList::findItem(int id) const {
    return binarySearch(id) != -1;
}

void SortedList::displayList() const {
    for (int i = 0; i < length; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int SortedList::binarySearch(int id) const {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (items[mid] == id) {
            return mid;
        } else if (items[mid] < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// =============================================================================

#include "SortedList.h"
#include <iostream>
using namespace std;

void insertItem(SortedList& list, int id);
void deleteItem(SortedList& list, int id);
void showMenu();
char getChoice();

int main() {
    SortedList list;
    char choice = ' ';
    int id = 0;

    while (true) {
        showMenu();
        choice = getChoice();

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
}

void insertItem(SortedList& list, int id) {
    if (!list.isFull()) {
        list.insertItem(id);
        cout << "Item inserted." << endl;
    } else {
        cout << "The list is full – cannot insert the number." << endl;
    }
}

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

void showMenu() {
    cout << "\nMenu:" << endl;
    cout << "a. Insert a number into the list." << endl;
    cout << "b. Delete a number from the list." << endl;
    cout << "q. Quit the program." << endl;
}

char getChoice() {
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return tolower(choice);
}
