// Attached: HW_4-2
// File: HW_4-2 - Linked List
// ============================================================================
// Programmer: William Kim
// Class: CMPR131
// Instructor: Med Mogasemi
// ============================================================================
// Program: Vehicle Linked List (HW_4-2)
// ============================================================================
// Description:
// This program creates a linked list of Vehicle struct objects. The user can
// insert at least 5 vehicles into the linked list, display the list, and
// search for a vehicle by ID.
// ============================================================================
// ============================================================================





// === Vehicle.h ==================================================================

#ifndef VEHICLE_H
#define VEHICLE_H
using namespace std;

#include <string>

struct Vehicle {
    int id;
    string model;
    Vehicle* next;
};

#endif //end of Vehicle.h
// ============================================================================





// ==== source.cpp =============================================================
//
// =============================================================================
#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

// Function prototypes
void insertVehicle(Vehicle*& head);
void displayVehicles(Vehicle* head);
void searchList(Vehicle* head, int id);

// ==== main ===================================================================
//
// =============================================================================
int main() {
    Vehicle* head = nullptr;
    char addMoreVehicles;

    // Insert at least 5 vehicles into the list
    do {
        insertVehicle(head);
        cout << "Enter another vehicle (Y or N)? ";
        cin >> addMoreVehicles;
    } while (addMoreVehicles == 'Y' || addMoreVehicles == 'y');

    // Prompt the user if they wish to see the list
    cout << "Display the list (Y/N)? ";
    char display;
    cin >> display;

    if (display == 'Y' || display == 'y') {
        displayVehicles(head);
    }

    // Prompt the user to search for a vehicle by ID
    cout << "Enter the ID of a vehicle to be found: ";
    int searchId;
    cin >> searchId;
    searchList(head, searchId);

    // Clean up memory
    while (head != nullptr) {
        Vehicle* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
} // end of main()
// =============================================================================






// ==== insertVehicle ==========================================================
//
// This function prompts the user for a vehicle ID and model, creates a new
// Vehicle object, and inserts it at the beginning of the linked list.
//
// Input:
// The head pointer to the linked list.
//
// Output:
// None.
// =============================================================================
void insertVehicle(Vehicle*& head) {
    int id;
    string model;

    cout << "ID: ";
    cin >> id;
    cout << "Model: ";
    cin.ignore(); // to ignore the newline character left by previous cin
    getline(cin, model);

    Vehicle* newVehicle = new Vehicle{id, model, head};
    head = newVehicle;
} // end of insertVehicle()







// ==== displayVehicles ========================================================
//
// This function traverses the linked list and displays the details of each
// Vehicle object.
//
// Input:
// The head pointer to the linked list.
//
// Output:
// Displays the ID and model of each Vehicle object.
// =============================================================================
void displayVehicles(Vehicle* head) {
    Vehicle* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << "\nModel: " << temp->model << endl;
        temp = temp->next;
    }
} // end of displayVehicles()







// ==== searchList =============================================================
//
// This function searches for a Vehicle object in the linked list by its ID and
// displays the details if found.
//
// Input:
// The head pointer to the linked list and the ID to be searched.
//
// Output:
// Displays the ID and model of the found Vehicle object or a message if not found.
// =============================================================================
void searchList(Vehicle* head, int id) {
    Vehicle* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "We found the vehicle!" << endl;
            cout << "ID: " << temp->id << "\nModel: " << temp->model << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "ID not found." << endl;
} // end of searchList()







// =============================================================================
/* ================================== Output ===================================
Enter vehicles into the list:
ID: 100
Model: Jeep
Enter another vehicle (Y or N)? y
ID: 101
Model: Toyota
Enter another vehicle (Y or N)? y
ID: 102
Model: Honda
Enter another vehicle (Y or N)? y
ID: 103
Model: Ford
Enter another vehicle (Y or N)? y
ID: 104
Model: Fiat
Enter another vehicle (Y or N)? n
Display the list (Y/N)? y

Here is the list:
ID: 104
Model: Fiat
ID: 103
Model: Ford
ID: 102
Model: Honda
ID: 101
Model: Toyota
ID: 100
Model: Jeep

Enter the ID of a vehicle to be found: 104
We found the vehicle!
ID: 104
Model: Fiat
*/
// =============================================================================
