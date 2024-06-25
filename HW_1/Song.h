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