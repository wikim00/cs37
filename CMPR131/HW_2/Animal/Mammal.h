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
