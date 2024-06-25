#ifndef PAINTING_H
#define PAINTING_H

#include "Art.h"
#include <iostream>
using namespace std;

class Painting : public Art {
private:
    string paintMedium;

public:
    Painting(string id, string title, string artist, string genre, int year, double price, string paintMedium)
        : Art(id, title, artist, genre, year, price), paintMedium(paintMedium) {}

    ~Painting() {}
    
    void showArt() const override {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Paint Medium: " << paintMedium << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

#endif
