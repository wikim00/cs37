#ifndef SCULPTURE_H
#define SCULPTURE_H

#include "Art.h"
#include <iostream>
using namespace std;

class Sculpture : public Art {
private:
    string material;

public:
    Sculpture(string id, string title, string artist, string genre, int year, double price, string material)
        : Art(id, title, artist, genre, year, price), material(material) {}

    ~Sculpture() {}
    
    void showArt() const override {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Material: " << material << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

#endif
