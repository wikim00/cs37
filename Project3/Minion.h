// Minion.h
// 
// declaration of the Minion class
// has five variables
// member function can 

#ifndef MINION_H_INCLUDED
#define MINION_H_INCLUDED

#include <string>
using namespace std;

class Minion {  
friend ostream operator<< (ostream&, Student&);
friend istream operator>> (istream&, Student&);

private:
    //private attributes
    string name;
    float height;
    int eyes;
    int bananasOwned;

    //private static variable
    static int minionCount;

public:
    //constructor
    Minion::Minion(string name, float height, int eyes, int bananasOwned);
    
    //initialize function
    int getBananas() const;
    string getName() const;
    static void printMinionCount();

    //overload operator(it's like a function)
    bool operator>(const Minion &other) const;
    bool operator<(const Minion &other) const;
};

#endif // MINION_H_INCLUDED