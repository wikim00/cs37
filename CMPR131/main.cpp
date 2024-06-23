// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Song
// =============================================================================
// Description: header, cpp, and main.cpp files to implement constructors and 
//              overloaded constructor and functions to output information about
//              songs that you input
// =============================================================================

#include <iostream>
#include "Song.h"

using namespace std;

int main() {
    // Declare Song objects
    Song yourSong; // Calls default constructor
    Song anotherSong("All of Me", "Billie Holliday"); // Calls overloaded constructor

    // Display both objects
    cout << "Here are the songs:" << endl;
    cout << "Your Song:" << endl;
    yourSong.displaySong(); // Should display empty strings

    cout << "Another Song:" << endl;
    anotherSong.displaySong(); // Should display "All of Me" and "Billie Holliday"

    // Prompt the user to enter the title and artist of your song
    string title, artist;
    cout << "Enter information about your song:" << endl;
    cout << "Title: ";
    getline(cin, title);
    cout << "Artist: ";
    getline(cin, artist);

    // Use set functions to assign the title and artist to yourSong object
    yourSong.setTitle(title);
    yourSong.setArtist(artist);

    // Display yourSong object after setting new values
    cout << "Here is your song (after the set functions):" << endl;
    yourSong.displaySong(); // Should display the entered title and artist

    cout << "Press any key to continue...";
    cin.get(); // Wait for user input before closing

    return 0;
}

/*
Your Song:
Title:
Artist:
Another Song:
Title: All of Me
Artist: Billie Holliday
Enter information about your song:
Title: Dead man walking
Artist: Madonna
Here is your song (after the set functions):
Title: Dead man walking
Artist: Madonna
Press any key to continue...
*/