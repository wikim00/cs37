// HW_2A
// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Art
// =============================================================================
// Description: This program displays abstract and derived classes in the forms
//              of derived class Painting and Sculpture.
//
// =============================================================================

// ==== Art.h ===============================================================
#ifndef ART_H
#define ART_H

#include <string>
using namespace std;

class Art {
protected:
    string id;
    string title;
    string artist;
    string genre;
    int year;
    double price;

public:
    Art(string id, string title, string artist, string genre, int year, double price)
        : id(id), title(title), artist(artist), genre(genre), year(year), price(price) {}

    virtual ~Art() {}
    
    virtual void showArt() const = 0; // Pure virtual function
};

#endif
// =============================================================================

// ==== Painting.h ===============================================================
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

// =============================================================================

// ==== Sculpture.h ===============================================================
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
// =============================================================================

// ==== Source.cpp ===============================================================
#include "Painting.h"
#include "Sculpture.h"
#include <iostream>
using namespace std;

void displayArt(Art &art) {
    art.showArt();
}

int main() {
    Painting a1("12345", "The Kiss", "Gustav Klimt", "Symbolist", 1908, 2500, "Oil");
    Sculpture a2("54321", "The Thinker", "Rodin", "Impressionism", 1880, 2000, "Bronze");

    displayArt(a1);
    cout << endl;
    displayArt(a2);

    return 0;
}

/* Output ===================================================================
ID: 12345
Title: The Kiss
Artist: Gustav Klimt
Paint Medium: Oil
Genre: Symbolist
Year: 1908
Price: $2500

ID: 54321
Title: The Thinker
Artist: Rodin
Material: Bronze
Genre: Impressionism
Year: 1880
Price: $2000
*/
// =============================================================================
