#include "Minion.h"
#include <string>
#include <iostream>
using namespace std;

// overloaded stream-insertion operator
// non member function via friend
ostream operator<< (ostream& os, const Minion&)
{
  os << "The minion " << minion.name << "is " << minion.height << " inches tall, has "
  << minion.eyes << " eye(s), and owns " << minion.bananasOwned << " banana(s)." << endl;
  return os;
}

// overloaded stream-insertion operator
istream operator>> (istream&, Minion&)
{

}

int main() {
    // // 1. Read File
    // ifstream combatFile("minions.txt");

    // //check if the file is open
    // if (!combatFile.is_open()){
    //     cout << "File fails to open" << endl;
    //     return 0;
    // }

    // //read the number of bots
    // int botsCount;
    // combatFile >> botsCount;



    // 2. Compare Height
    //Find the taller minion

    /* if (minion1 > minion2) 
    {
    cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) 
    {
    cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl; */

    // 3. Get Bananas


    return 0;
}
