// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Reverse_Order
// =============================================================================
// Description: This program allows the user to enter 5 cities, and then choose
//              whether to display the cities in order or in reverse order.
//
// =============================================================================

#include <iostream>
#include <array>
#include <string>

using namespace std;

constexpr int cityCount = 5;

void getCities(array<string, cityCount>& cities) {
    cout << "Enter 5 cities:" << endl;
    for (int i = 0; i < cityCount; i++) {
        cout << (i + 1) << ": ";
        getline(cin, cities[i]);
    }
}

char getChoice() {
    char choice;
    cout << "Enter O for in order or R for in reverse: ";
    cin >> choice;
    cin.ignore(); // To clear the newline character from the buffer
    return choice;
}

void displayInOrder(const array<string, cityCount>& cities) {
    cout << "Here are the cities in order:" << endl;
    for (const auto& city : cities) {
        cout << city << " ";
    }
    cout << endl;
}

void displayInReverse(const array<string, cityCount>& cities) {
    cout << "Here are the cities in reverse order:" << endl;
    for (int i = cityCount - 1; i >= 0; i--) {
        cout << cities[i] << " ";
    }
    cout << endl;
}

int main() {
    array<string, cityCount> cities;
    char runAgain;

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
}

/*
Enter 5 cities:
1: Corona
2: Anaheim
3: Santa Ana
4: Brea
5: Fullerton
Enter O for in order or R for in reverse: O
Here are the cities in order:
Corona Anaheim Santa Ana Brea Fullerton 
Run program again (y / n)? y
----- (screen clears) -----------------------------------
*/