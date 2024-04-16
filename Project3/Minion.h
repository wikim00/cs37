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
friend ostream& operator<< (ostream&, const Minion&);
friend istream& operator>> (istream&, Minion&);

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
    Minion(string name, float height, int eyes, int bananasOwned);
    
    //initialize function
    int getBananas() const;
    string getName() const;
    float getHeight();
    int getEyes();
    int getBananasOwned();
    static void printMinionCount();

    //overload operator(it's like a function)
    bool operator>(const Minion &other) const;
    bool operator<(const Minion &other) const;
    Minion &operator++();   //preincrement
    Minion operator++(int); //postincrement
};

#endif // MINION_H_INCLUDED