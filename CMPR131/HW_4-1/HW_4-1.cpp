// Attached: HW_4-1(a,b)
// File: HW_4-1b
// ============================================================================
// Programmer: William Kim
// Class: CMPR131
// Instructor: Med Mogasemi
// ============================================================================
// Program: Dog Linked List (HW_4-1)
// ============================================================================
// Description:
// This program creates a linked list of Dog stuct objects.
// ============================================================================
// ============================================================================






// === Dog.h =================================================================

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
using namespace std;

struct Dog
{
    // create variables
    int id;
    string name;
    Dog* next;
};

#endif // end of Dog.h
// ============================================================================





// ==== source.cpp =============================================================
//
// =============================================================================
#include "Dog.h"

using namespace std;

// Function prototypes
void insertDog(Dog*& head, int id, string name);
void displayList(Dog* head);
void deleteDog(Dog*& head, int id);

// ==== main ===================================================================
//
// =============================================================================
int main()
{
    Dog* head = nullptr;
    char addMoreDogs;

    // While loop to insert at least 3 dogs into the list
    do {
        int id;
        string name;

        cout << "Enter dog's ID: ";
        cin >> id;
        cout << "Enter dog's name: ";
        cin >> name;

        insertDog(head, id, name);

        cout << "Enter another dog (Y or N)? ";
        cin >> addMoreDogs;
    } while (addMoreDogs == 'Y' || addMoreDogs == 'y');

    // Prompt the user if they wish to see the list
    cout << "Display the list (Y/N)? ";

    char display;
    cin >> display;

    if (display == 'Y' || display == 'y') {
        displayList(head);
    }

    // Prompt the user to delete a dog by ID
    cout << "Enter an ID of a dog to be deleted: ";
    int deleteId;
    cin >> deleteId;
    deleteDog(head, deleteId);

    // Display the list after deletion
    cout << "Here is the list after the delete:\n";
    displayList(head);

    // Clean up memory
    while (head != nullptr) {
        Dog* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
} // end of main()
// =============================================================================






// === InsertDog ==========================================================
//
// This function prompts user for info about dog and creates object into the
// linked list.
// =============================================================================

void insertDog(Dog*& head, int id, string name) {
    Dog* newDog = new Dog{id, name, nullptr};

    if (head == nullptr) {
        head = newDog;
    } else {
        Dog* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newDog;
    }
} // end of insertDog()
// =============================================================================





// ==== displayList  ========================================================
//
// This function traverses the linked list and displays the details of each
// object.
// =============================================================================

void displayList(Dog* head) {
    Dog* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << "\nName: " << temp->name << endl;
        temp = temp->next;
    }
} // end of display list
// =============================================================================





// === deleteDog ===================================================================
// 
// Function checks for id and deletes object. If not found, then it returns not on the
// list
//
// =============================================================================

void deleteDog(Dog*& head, int id) {
    Dog* temp = head;
    Dog* prev = nullptr;

    // keep moving through the  list
    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    // checks if its the last / null pointer so no more left
    if (temp == nullptr) {
        cout << id << " is not in the list." << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "The dog has been deleted." << endl;
} // end of delete dog





// =============================================================================
/* ================================== Output ===================================
/*
Enter dog's ID: 123
Enter dog's name: Rex
Enter another dog (Y or N)? y
Enter dog's ID: 1234
Enter dog's name: Dog
Enter another dog (Y or N)? Y
Enter dog's ID: 12345
Enter dog's name: Boy
Enter another dog (Y or N)? Y
Enter dog's ID: 123456
Enter dog's name: asdf
Enter another dog (Y or N)? N

Display the list (Y/N)? Y

ID: 123
Name: Rex
ID: 1234
Name: Dog
ID: 12345
Name: Boy
ID: 123456
Name: asdf

Enter an ID of a dog to be deleted: 123456
The dog has been deleted.
Here is the list after the delete:
ID: 123
Name: Rex
ID: 1234
Name: Dog
ID: 12345
Name: Boy
*/
// =============================================================================
