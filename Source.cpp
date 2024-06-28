// Linked List Extra Credit
// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Week2 Linked List
// =============================================================================
// Description: This program displays abstract and derived classes in the forms
//              of derived class Painting and Sculpture.
//
// =============================================================================

#include <iostream>
using namespace std;

struct Box {
    int id;
    // pointer for the next Box
    Box* next;
};

void insert(Box*& head);
void display(Box*& head);
void deleteBox(Box*& head);

int main()
{
    Box* head = nullptr;
    int number = 0;
    char answer = ' ';
    
    cout << "How many boxes do you want: ";
    cin >> number;
    for (int i = 0; i < number; i++) {
        cout << "Id for Box #" << i + 1 << ": ";
        insert(head);
    }
    
    cout << "Here are the ID's from the Boxes:\n\n";
    display(head);
    
    cout << "Would like to delete a Box? (Y or N): ";
    cin >> answer;
    while (answer == 'Y' || answer == 'y') {
        deleteBox(head);
        cout << "Delete another one? (Y or N): ";
        cin >> answer;
    }
    
    cout << "Here is the data after deleting the Box or Boxes,\n\n";
    display(head);

    cout << endl << endl;
    return 0;
}

void insert(Box*& head)
{
    Box* ptr = new Box();
    cout << "Please enter the id: ";
    cin >> ptr->id;
    ptr->next = head;
    head = ptr;
}

void display(Box*& head)
{
    Box* print = head;
    while (print != nullptr) {
        cout << print->id << endl;
        print = print->next;
    }
    cout << endl << endl;
}

void deleteBox(Box*& head)
{
    int idNum = 0;

    cout << "Which Box do you want to delete (Enter the Id number): ";
    cin >> idNum;
    
    if (head == nullptr) {
        cout << "Sorry, the list is empty.\n\n";
        return;
    }
    
    Box* lead = head;
    Box* follow = nullptr;
    
    // Special case for deleting the head node
    // checks if id of the head matches the one we want to delete
    if (lead->id == idNum) {
        // head node must be deleted and update head to next node
        // like vice president is the head after president
        head = head->next;
        // delete original head node
        delete lead;
        return;
    }
    
    // loop keeps going forward down list
    while (lead != nullptr && lead->id != idNum) {
        //follow is used to keep track of the previous node
        // lead moves forward
        follow = lead;
        //moves lead to the next node in the list
        lead = lead->next;
    }
    
    // If the node was found, remove it
    // checks if node with matching id was foun
    if (lead != nullptr) {
        // removing the lead from list by skipping it
        follow->next = lead->next;
        delete lead;
    } else {
        // means node with id was not found in the list
        cout << "Box with id " << idNum << " not found.\n\n";
    }
}

// =====Output========================================================================
/*

How many boxes do you want: 5
Id for Box #1: Please enter the id: 1
Id for Box #2: Please enter the id: 2
Id for Box #3: Please enter the id: 3
Id for Box #4: Please enter the id: 4
Id for Box #5: Please enter the id: 5
Here are the ID's from the Boxes:

5
4
3
2
1


Would like to delete a Box? (Y or N): y
Which Box do you want to delete (Enter the Id number): 5
Delete another one? (Y or N): n
Here is the data after deleting the Box or Boxes,

4
3
2
1
*/