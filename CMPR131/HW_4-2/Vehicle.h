#ifndef VEHICLE_H
#define VEHICLE_H
using namespace std;

#include <string>

struct Vehicle {
    int id;
    string model;
    Vehicle* next;
};

#endif
