#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib> // Include for proper file handling
#include <algorithm> // copy_n function
using namespace std;

//class to contain bots and their functions
class Battle {
private:
    //initialize botsPower and botsCount
    int botsPower[10], botsCount; 
    float bossPower;

public:
    //constructor
    dvaBattle(int botsPower[], int botsCount, float bossPower);

    
};

//class to contain mech and functions
class Mech {

};

//matrix_power function will take in bots' power, number of bots, and boss's power
//and calculate how much defense matrix dva needs
float matrix_power(int botsPower[], int botsCount, float bossPower) {
    float sum = 0;
    for (int i = 0; i < botsCount; i++)
    {
        sum += botsPower[i];
    }
    sum += bossPower;
    return sum; //return statement
}

//single_missile power function takes in an integer or float as a parameter
//using template convert to the appropriate unit
template <typename U>
U single_missile_power(U a)
{
    //if a <= 15 return 2x
    if (a <= 15)
    {
        return a * 2;
    }

    //if a > 15 return 5x
    else if (a > 15)
    {
        return a * 5;
    }
}

//function overloading load_dva to see how much defense matrix and missiles D.Va needs
void load_dva(float& defenseMatrix, float& matrixPowerRequired) 
{
    //pass by reference for this function
    if (defenseMatrix < matrixPowerRequired)
    {
        defenseMatrix = matrixPowerRequired;
    }

}

void load_dva(int& microMissiles, float& missilePowerRequired)
{
    //pass in by reference
    //make missile power required and divide it to 60 to make it compatible
    missilePowerRequired = ceil(missilePowerRequired / 60);
    if (microMissiles < missilePowerRequired)
    {
        microMissiles = missilePowerRequired;
    }

}

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

    //initialize battle and dva class
    Battle dvaBattle(botsPower[i], botsCount, bossPower);
    Mech dva;

    //read microMissiles and defenseMatrix 
    int microMissiles;
    float defenseMatrix;
    combatFile >> microMissiles;
    combatFile >> defenseMatrix;
    cout << "# of micro missiles: " << microMissiles << endl;
    cout << "defense matrix: " << defenseMatrix << endl;

    //calculate and load defense matrix
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);
    cout << "matrix power required: " << matrixPowerRequired << endl;
    
    //2. Load Micro Missiles
    //single missile power
    float missilePowerRequired = 0;
    
    //add up the single missile power of each bot in the array
    for(i = 0; i < botsCount; i++)
    {
    missilePowerRequired += single_missile_power(botsPower[i]);
    cout << "single missile power for bot# "<< single_missile_power(botsPower[i]) << endl;
    }

    //add up the bosses power up
    cout << "missile power for boss "<< single_missile_power(bossPower) << endl;
    missilePowerRequired += single_missile_power(bossPower);
    cout << "total missile power required: " << missilePowerRequired << endl;

    //3. Load D.VA

    //take in defense Matrix by reference and matrxiPowerRequired by value
    load_dva(defenseMatrix, matrixPowerRequired);
    load_dva(microMissiles, missilePowerRequired);
    cout << "loaded defense matrix: " << defenseMatrix << " loaded matrix power required: " << matrixPowerRequired << endl;
    cout << "loaded micro missiles: " << microMissiles << " loaded missile power required: " << missilePowerRequired << endl;

    //4. Report
    //use ofstream to open file
    ofstream report("report.txt");
    
    //check file open
    if (!report.is_open()){
        cout << "File fails to open" << endl;
        return 0;
    }
    
    //write to file
    report << "D.Va's Combat Report" << endl;
    report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << endl;
    report << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << endl;
    report << "Ready for combat!";
    //close file
    report.close();
    combatFile.close();
    
    return 0;
}