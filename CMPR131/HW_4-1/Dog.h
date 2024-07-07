#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
using namespace std;

struct Dog
{
    int id;
    string name;
    Dog* next;
};

#endif
