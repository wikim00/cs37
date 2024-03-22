#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib> // Include for proper file handling
#include <algorithm> // copy_n function
using namespace std;

//class to contain bots and their functions
class Battle {  
friend class Mech;

private:
    //initialize botsPower and botsCount
    int botsPower[10], botsCount; 
    float bossPower;

public:
    //constructor
    Battle(int botsPower[], int botsCount, float bossPower) {
        copy_n(botsPower, botsCount, this->botsPower);
        this->botsCount = botsCount;
        this->bossPower = bossPower;
    };

    //calculate total matrix power required
    float matrix_power(int botsPower[], int botsCount, float bossPower) {
        float sum = 0;
        for (int i = 0; i < botsCount; i++)
        {
            sum += botsPower[i];
        }
        return sum + bossPower; 
    };
};

//class to contain mech and functions
class Mech {
private:
    float defenseMatrix;
    int microMissiles;

public:
    Mech(float defenseMatrix, int microMissiles) : 
    defenseMatrix(defenseMatrix), microMissiles(microMissiles) {}


    float micro_missile(Battle &battle) {
        //micro missile = 2*Sum(botsPower) + 5*bossPower
        float sum = 0;
        for (int i = 0; i < battle.botsCount; i++) {
            sum += battle.botsPower[i];
        }
        return 2 * sum + 5 * battle.bossPower;
    };

    void load(float matrixPowerRequired, float missilePowerRequired){
        //overwrite class member if "required" is greater than default
        if(matrixPowerRequired > defenseMatrix)
        {
            defenseMatrix = matrixPowerRequired;
        }
        
        missilePowerRequired = ceil(missilePowerRequired / 60);
        if (microMissiles < missilePowerRequired)
        {
            microMissiles = missilePowerRequired;
        }

    }
};

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
    Battle dvaBattle(botsPower[], botsCount, bossPower);
    Mech dva(100.0, 10);

    //calculate power needed
    float matrixPowerRequired = dvaBattle.matrix_power();
    float missilePowerRequired = dva.micro_missile(dvaBattle);


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
    report << "Loaded mech with " << dva.microMissiles << " micro missiles and the defense matrix with power " << dva.defenseMatrix << endl;
    report << "Ready for combat!";
    //close file
    report.close();
    combatFile.close();
    
    return 0;
}