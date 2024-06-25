#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <iostream>
using namespace std;

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
