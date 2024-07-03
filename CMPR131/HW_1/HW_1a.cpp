// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Reverse_Order (HW_1a)
// =============================================================================
// Description: This program allows the user to enter 5 cities, and then choose
//              whether to display the cities in order or in reverse order.
//
// =============================================================================
// =============================================================================

#include <iostream>
#include <array>
#include <string>

using namespace std;

// const size of array
const int cityCount = 5;

// Function Prototypes
void getCities(array<string, cityCount>& cities);
char getChoice();
void displayInOrder(const array<string, cityCount>& cities);
void displayInReverse(const array<string, cityCount>& cities);

// ==== main ===================================================================
//
// =============================================================================
int main() {
    // declaring variables
    array<string, cityCount> cities;
    char runAgain;

    //function that gives choices for how to organize cities
    do {
        getCities(cities);

        char choice = getChoice();
        switch (choice) {
            case 'O':
            case 'o':
                displayInOrder(cities);
                break;
            case 'R':
            case 'r':
                displayInReverse(cities);
                break;
            default:
                cout << "Invalid entry - Must be O or R!" << endl;
                break;
        }

        // repeat the program?
        cout << "Run program again (y / n)? ";
        cin >> runAgain;
        cin.ignore(); // To clear the newline character from the buffer
        if (runAgain == 'y' || runAgain == 'Y') {
            cout << "----- (screen clears) -----------------------------------" << endl;
        }
    } while (runAgain == 'y' || runAgain == 'Y');

    cout << "Press any key to continue ...";
    cin.get();

    return 0;
} // end of main

// ============================================================================









// ======= getCities ============================================================
// This function prompts the user to input 5 cities and uses a loop to read line
// five times.
//
// Output: returns array of cities
// =============================================================================

void getCities(array<string, cityCount>& cities) {
    //prompt
    cout << "Enter 5 cities:" << endl;

    //loop 5 times to get inputs
    for (int i = 0; i < cityCount; i++) {
        cout << (i + 1) << ": ";
        getline(cin, cities[i]);
    }
} // end of getCities()








// ==== getChoice ==============================================================
// This function gets user input to choose if the cities order will be reversed
// or not
//
// Input:
// User choice Char (o) for in order (r) for in reverse
//
// Output:
// Returns character
// =============================================================================

char getChoice() {
    char choice;

    // reads choice to decide to call cities in order or reverse order
    cout << "Enter O for in order or R for in reverse: ";
    cin >> choice;

    cin.ignore(); // To clear the newline character from the buffer

    return choice;
} // end of getChoice
// =============================================================================






// ==== displayInOrder ==============================================================
// This function displays cities in order
//
// Input:
// array of cities
//
// Output:
// Returns output of cities in order
// =============================================================================

void displayInOrder(const array<string, cityCount>& cities) {
    // message to show order was selected
    cout << "Here are the cities in order:" << endl;

    //loops through array
    for (int i = 0; i < cityCount; i++) {
        cout << cities[i] << " ";
    }
    cout << endl;
} // end of displayInOrder
// =============================================================================






// ==== displayInReverse ==============================================================
// This function displays cities in reverse
//
// Input:
// array of cities
//
// Output:
// Returns output of cities in reverse
// =============================================================================

void displayInReverse(const array<string, cityCount>& cities) {
    //prompt
    cout << "Here are the cities in reverse order:" << endl;

    //loops through array in reverse order
    for (int i = cityCount - 1; i >= 0; i--) {
        cout << cities[i] << " ";
    }
    cout << endl;
} // end of displayInReverse
// =============================================================================






/* ==Output=======================================================================
Enter 5 cities:
1: Corona
2: Anaheim
3: Santa Ana
4: Brea
5: Fullerton

Enter O for in order or R for in reverse: O

Here are the cities in order:

Corona Anaheim Santa Ana Brea Fullerton 

Run program again (y / n)? n

Press any key to continue ... 
*/
