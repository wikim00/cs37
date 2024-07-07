// Attached: HW_2B
// File: HW_2B.cpp
// =============================================================================
//
// Programmer: William Kim
// Class: CMPR 131
// Instructor: Med Mogasemi
//
// =============================================================================
// Program: Animal
// =============================================================================
// Description: This program displays abstract and derived classes in the forms
//              of derived class Bird and mammal and have the function show animal
//              inside of the derived class but declared in the abstract Animal class
// =============================================================================
// =============================================================================






// ==== Animal.h ===============================================================
//  base abstract class with virtual function to set up derived classes bird
// and mammal.
// =============================================================================
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
protected:
    //member variables
    string name;
    double weight;

public:
    //constructor, destructor
    Animal(string name, double weight) : name(name), weight(weight) {}
    virtual ~Animal() {}
    virtual void showAnimal() const = 0; // Pure virtual function
}; // end of Animal.h

#endif
// =============================================================================






// ==== Bird.h =====================================================================
//  Derived class using Animal.h as base
// =============================================================================
#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Bird : public Animal {
private:
    // additional member variable
    string featherColor;

public:
    // constructor/ destructor
    Bird(string featherColor, double weight)
        : Animal("Bird", weight), featherColor(featherColor) {}
    ~Bird() {}
    
    // function to display info about bird
    void showAnimal() const override {
        cout << "Birds are vertebrates in the Aves class." << endl;
        cout << "This pelican has " << featherColor << " feathers and weighs " << weight << " pounds." << endl;
    }
}; // end of Bird.h

#endif
// =============================================================================






// ==== Mammal.h ===============================================================
// Derived class using Animal.h as base
// =============================================================================
#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Mammal : public Animal {
private:
    // member variable color
    string hairColor;

public:
    //constructor, destructor
    Mammal(string hairColor, double weight)
        : Animal("Mammal", weight), hairColor(hairColor) {}
    ~Mammal() {}

    // function to display info about mammal
    void showAnimal() const override {
        cout << "Mammals are vertebrates in the Mammalia class." << endl;
        cout << "This black and white dairy cow weighs " << weight << " pounds." << endl;
    }
}; // end of Mammal.h

#endif
// ===================================================================






// ==== Source.cpp ===============================================================
//
// =============================================================================

#include "Bird.h"
#include "Mammal.h"
#include <iostream>
using namespace std;

int main() {
    // declare Bird object with feather color and weight
    Bird bird("gray", 8.5);

    // declare Cow object with colors and weight
    Mammal cow("black and white", 500.0);

    // display functions
    bird.showAnimal();
    cout << endl;
    cow.showAnimal();

    return 0;
}

/* Output ==================================================================
Birds are vertebrates in the Aves class.
This pelican has gray feathers and weighs 8.5 pounds.

Mammals are vertebrates in the Mammalia class.
This black and white dairy cow weighs 500 pounds.
*/
// =============================================================================
