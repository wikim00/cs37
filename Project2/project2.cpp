#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//read combat data and then adjust dva to defeat her enemies

int main() {

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
    cout << "# of bots: "<< botsCount << endl;

    //for loop to add botsPower into an array
    int i;
    for(i = 0; i < botsCount; i++)
    {
        combatFile >> botsPower[i];
        cout << "bot #" << i << " power: " << botsPower[i] << endl; 
    }

    //read boss power last outside of loop
    float bossPower;
    combatFile >> bossPower;
    cout << "boss power: " << bossPower << endl;

    //read microMissiles and defenseMatrix 
    int microMissiles;
    float defenseMatrix;
    combatFile >> microMissiles;
    combatFile >> defenseMatrix;
    cout << "# of micro missiles: " << microMissiles << endl;
    cout << "defense matrix: " << defenseMatrix << endl;


}