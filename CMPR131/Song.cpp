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
