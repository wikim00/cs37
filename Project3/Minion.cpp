// Minion.cpp
// 
// this is the source of the minions class
// 

#include "Minion.h"
#include <string>
#include <iostream>

using namespace std;

// initialize static member variable
int Minion::minionCount = 0;

// constructor definition
Minion::Minion(string name, float height, int eyes, int bananasOwned) {
    this->name = name;
    this->height = height;
    this->eyes = eyes;
    this->bananasOwned = bananasOwned;
    minionCount++; // Increment minionCount every time a new Minion object is created
}

//define functions
int Minion::getBananas() const
{   //const lets us access bananas owned
    return bananasOwned;
}

string Minion::getName() const
{   //const lets us access name
    return name;
}

// Member functions to access private attributes
float Minion::getHeight()  {
    return height;
}

int Minion::getEyes()  {
    return eyes;
}

int Minion::getBananasOwned()  {
    return bananasOwned;
}

void Minion::printMinionCount() 
{
  cout << minionCount << " minions created." << endl;
}

//define overloaded operators
//comparing heights operators
bool Minion::operator>(const Minion &other) const 
{
    //if current height > compared height then TRUE
    return height > other.height;
}

bool Minion::operator<(const Minion &other) const 
{
    //if current is shorter than compared then TRUE
    return height < other.height;
}

// preincrement
Minion& Minion::operator++() {
    ++bananasOwned;
    return *this;
}

// postincrement
Minion Minion::operator++(int) {
    Minion temp = *this;
    ++(*this);  // Call the pre-increment operator to increase bananasOwned
    return temp;
}
