#include "Minion.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Define the friend functions for the stream operators (ostream and istream)
// Overloaded stream-insertion operator
ostream &operator<<(ostream &os, const Minion &minion)
{
  os << "The minion " << minion.getName() << " is " << minion.height << " inches tall, has "
     << minion.eyes << " eye(s), and owns " << minion.bananasOwned << " banana(s)." << endl;
  return os;
}

// Overloaded stream-extraction operator
istream &operator>>(istream &is, Minion &minion)
{
  // Read data into variables
  string name;
  float height;
  int eyes;
  int bananasOwned;

  // Extract data from input stream
  is >> name >> height >> eyes >> bananasOwned;

  // Assign extracted data to the Minion object
  minion = Minion(name, height, eyes, bananasOwned);

  // Return the input stream
  return is;
}

int main()
{

  // declare minion objects
  Minion minion1("Kevin", 38, 2, 1); 
  Minion minion2("", 0.0f, 0, 0);
  Minion minion3("", 0.0f, 0, 0);

  // 1. Read File
  ifstream file("minions.txt");

  // check if the file is open
  if (!file.is_open())
  {
    cout << "File fails to open" << endl;
    return 0;
  }

  // read minion information from file
  string name;
  float height;
  int eyes;
  int bananasOwned;

  // Read data from file into minion objects using the overloaded operator
  file >> minion1 >> minion2 >> minion3;

  // Close the file
  file.close();

  // 2. Compare Height
  // Find the taller minion

  if (minion1 > minion2)
  {
    cout << minion1.getName() << " is taller than " << minion2.getName();
  }
  if (minion2 < minion3)
  {
    cout << minion3.getName() << " is taller than " << minion2.getName();
  }
  cout << endl << endl;

  // 3. Get Bananas
  cout << minion2; 
  cout << minion2.getName() << " getting bananas." << endl;
  cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

  cout << minion3;
  cout << minion3.getName() << " getting bananas." << endl;
  cout << "Before getting bananas, the minion had " << (minion3++).getBananas() << " banana(s)." << endl;
  cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s)." << endl << endl;

  // 4. Get minion count
  Minion::printMinionCount();
  return 0;
}