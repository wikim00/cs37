// Attached: HW_1b
// File: HW_1b.cpp
// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Reverse_Order (HW_1b)
// =============================================================================
// Description: Description: This program utilizes C-strings for names and lengths
// =============================================================================
// =============================================================================

#include <iostream> 
#include <cstring>  // For C-string functions like strcpy and strcat
#include <string>   // For the C++ string class

using namespace std;

// ==== main ===================================================================
//
// =============================================================================
int main() {
    //size of arrays
    const int SIZE = 20;
    const int FULL_SIZE = 40;

    char firstAndMiddle[SIZE];
    char lastName[SIZE];
    char fullName[FULL_SIZE];
    string friendsName;

    // Prompt the user to enter first and middle names
    cout << "Enter your first and middle names: ";
    cin.getline(firstAndMiddle, SIZE);

    // Prompt the user to enter a last name
    cout << "Enter your last name: ";
    cin.getline(lastName, SIZE);

    // Combine firstAndMiddle and lastName into fullName
    strcpy(fullName, firstAndMiddle);
    strcat(fullName, " ");
    strcat(fullName, lastName);

    // Display messages
    cout << "How is your love life " << fullName << "?" << endl;
    cout << "By the way, your full name has " << strlen(fullName) << " characters." << endl;

    // Prompt the user to enter a friend's full name
    cout << "Enter your friend’s full name: ";
    getline(cin, friendsName);

    // display message about friend
    cout << "How is " << friendsName << " love life " << firstAndMiddle << "?" << endl;
    cout << "By the way, your friend’s full name has " << friendsName.length() << " characters." << endl;

    cout << "Press any key to continue ...";
    cin.get();

    return 0;
} // end of main()
// =============================================================================






// ==OUTPUT=======================================================================
/*
Enter your first and middle names: Tom
Enter your last name: Lee
How is your love life Tom Lee?
By the way, your full name has 7 characters.

Enter your friend’s full name: William Kim
How is William Kim love life Tom?
By the way, your friend’s full name has 11 characters.

Press any key to continue ...
*/