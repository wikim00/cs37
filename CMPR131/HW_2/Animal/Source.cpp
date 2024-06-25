// HW_2B
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

// ==== Animal.h ===============================================================
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
protected:
    string name;
    double weight;

public:
    Animal(string name, double weight) : name(name), weight(weight) {}
    virtual ~Animal() {}
    virtual void showAnimal() const = 0; // Pure virtual function
};

#endif
// =============================================================================

#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
using namespace std;

// ==== Bird.h ===============================================================

class Bird : public Animal {
private:
    string featherColor;

public:
    Bird(string featherColor, double weight)
        : Animal("Bird", weight), featherColor(featherColor) {}

    ~Bird() {}
    
    void showAnimal() const override {
        cout << "Birds are vertebrates in the Aves class." << endl;
        cout << "This pelican has " << featherColor << " feathers and weighs " << weight << " pounds." << endl;
    }
};

#endif
// =============================================================================

// ==== Mammal.h ===============================================================

#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Mammal : public Animal {
private:
    string hairColor;

public:
    Mammal(string hairColor, double weight)
        : Animal("Mammal", weight), hairColor(hairColor) {}

    ~Mammal() {}

    void showAnimal() const override {
        cout << "Mammals are vertebrates in the Mammalia class." << endl;
        cout << "This black and white dairy cow weighs " << weight << " pounds." << endl;
    }
};

#endif
// ===================================================================

// ==== Source.cpp ===============================================================
#include "Bird.h"
#include "Mammal.h"
#include <iostream>
using namespace std;

int main() {
    Bird bird("gray", 8.5);
    Mammal cow("black and white", 500.0);

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