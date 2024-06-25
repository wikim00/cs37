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

/*
Birds are vertebrates in the Aves class.
This pelican has gray feathers and weighs 8.5 pounds.

Mammals are vertebrates in the Mammalia class.
This black and white dairy cow weighs 500 pounds.
*/