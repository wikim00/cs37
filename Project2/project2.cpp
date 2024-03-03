#include <iostream>
#include <string>
using namespace std;


//read combat data and then adjust dva to defeat her enemies

int main() {

    ifstr
    //open file
    ifstream combatFile("combat.txt");
    //check if the file is open
    if (!combatFile.is_open()){
        cout << "File fails to open" << endl;
        return 0;
    }

    //read the number of bots
    int botsCount;
    combatFile >> botsCount;
    //array to store the botsPower
    int botsPower[botsCount];

    for(i < botsPower, i++) {

    }
}