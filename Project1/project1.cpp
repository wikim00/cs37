/*William Kim
Assignment: Project 1
Date: 02/18/2024
Create structureto read inputs and get user information
and then output total accountBalance, highest bank account,
# of swedish people, and if there is anyone younger than 21 
*/

#include <iostream>
#include <string>
#include <iomanip> // get setprecision ability
using namespace std;

//structure creates an object i guess to store information in an
// organized fashion
struct userAccount {
    /* structure to store info on user*/
    string username;
    string nationality;
    int age;
    float accountBalance;

    //initialize float variable to track the highest balance
    float highestBalance = 0.0;
};

int main() {
    // Create an array of user struct holding up to 20 accounts
    userAccount accts[20];

    // instruction
    cout << "Please enter information to database like this: <username> <nationality> <age> <accountBalance>, and separate each new user each line" << endl;

    // read in user name and age into struct
    string name, nationality;
    int age;
    float accountBalance;
    int userCount = 0;

    // storage variables
    float highestBalance = 0.00;
    float balanceSum = 0.00;
    int swedishUser = 0;
    bool iszoomer = false;

    while (userCount < 20 && cin >> name >> nationality >> age >> accountBalance) {
        // store user infomration in struct
        accts[userCount].username = name;
        accts[userCount].nationality = nationality;
        accts[userCount].age = age;
        accts[userCount].accountBalance = accountBalance;
        
       //update totals
       balanceSum += accountBalance;
       if(accountBalance > highestBalance) {
        highestBalance = accountBalance;
       } 
       
       //if there's a swedish person, add to the count
       if(nationality == "Swedish"){
        swedishUser++;
       } 
       
       //if there's anyone under 21, make true
       if(age < 21) {
        iszoomer = true;
       }
       
       // add one to total of users
        userCount++;
    }

    // Output questions and answers
    cout << "Q: What is the highest account balance among all users?" << endl;
    cout << "A: $" << fixed << setprecision(2) << highestBalance << endl; //setprecision 2 for 2 decimal places
    

    cout << "Q: What's the sum of account balance of all users?" << endl;
    cout << "A: $" << fixed << setprecision(2) << balanceSum << endl;

    cout << "Q: How many users come from Sweden?" << endl;
    cout << "A: " << swedishUser << endl;

    cout << "Q: Do we have any user younger than 21?" << endl;
    cout << "A: " << (iszoomer ? "Yes" : "No") << endl;
    return 0;
};