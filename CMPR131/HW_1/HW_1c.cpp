// Attached: HW_1c
// file: HW_1c.cpp
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






// =============================================================================
// Song.h
// =============================================================================

#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
private:
    string title;
    string artist;

public:
    // Default constructor
    Song();

    // Overloaded constructor
    Song(string title, string artist);

    // Destructor
    ~Song();

    // Setters
    void setTitle(string title);
    void setArtist(string artist);

    // Display function
    void displaySong() const;
};

#endif
// =============================================================================






// =============================================================================
// Song.cpp
// =============================================================================

#include "Song.h"
#include <iostream>
using namespace std;

// Default constructor
Song::Song() : title(""), artist("") {}

// Overloaded constructor
Song::Song(string title, string artist) : title(title), artist(artist) {}

// Destructor
Song::~Song() {}

// Setter for title
void Song::setTitle(string title) {
    this->title = title;
}

// Setter for artist
void Song::setArtist(string artist) {
    this->artist = artist;
}

// Function to display song information
void Song::displaySong() const {
    cout << "Title: " << title << endl;
    cout << "Artist: " << artist << endl;
}
// =============================================================================






// =============================================================================
// main.cpp
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

    cout << "Press any key . . . ";
    cin.get(); // Wait for user input before closing

    return 0;
} // end of main.cpp
// =============================================================================






// ==Output======================================================================

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
Press any key . . .
*/
// =============================================================================
