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
