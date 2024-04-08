#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#ifndef minions
#define minions

class Minion {  

private:
    //private attributes
    string name;
    float height;
    int eyes;
    int bananasOwned;

    //private static variable
    static int minionCount;
};

#endif // minion