// Attached: HW_2a
// File: HW_2a.cpp
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
// =============================================================================





// ==== Art.h ==================================================================
//  creates abstract base class with information about art to derive classes from
// =============================================================================
#ifndef ART_H
#define ART_H

#include <string>
using namespace std;

class Art {
protected:
    //initialize variables
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
}; // end of Art.h

#endif
// =============================================================================





// ==== Painting.h ===============================================================
// Derive the class from Art.h and makes it into painting. 
// =============================================================================
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

    // overriding virtual function
    void showArt() const override {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Paint Medium: " << paintMedium << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
}; // end of Painting.h

#endif
// =============================================================================






// ==== Sculpture.h ===============================================================
//
// =============================================================================
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
    
    // overriding virtuatl function
    void showArt() const override {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Material: " << material << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
}; // end of Sculpture.h

#endif
// =============================================================================






// ==== Source.cpp ===============================================================
//  
// =============================================================================
#include "Painting.h"
#include "Sculpture.h"
#include <iostream>
using namespace std;

// function prototype
void displayArt(Art &art);

int main() {
    Painting a1("12345", "The Kiss", "Gustav Klimt", "Symbolist", 1908, 2500, "Oil");
    Sculpture a2("54321", "The Thinker", "Rodin", "Impressionism", 1880, 2000, "Bronze");

    displayArt(a1);
    cout << endl;
    displayArt(a2);

    return 0;
} // end of main
// =============================================================================





// ==== displayArt===============================================================
// This function displays art by passing object to the function
// =============================================================================
void displayArt(Art &art) {
    art.showArt();
} // end of displayArt

// =============================================================================






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
