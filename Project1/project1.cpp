#include <iostream>
#include <string>
using namespace std;

//initialize float variable to track the highest balance

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
    cout << "Please enter information to database like this: <username> <nationality> <age> <accountBalance>, and separate each new user using ENTER" << endl;

    // read in user name and age into struct
    string name, nationality;
    int age;
    float accountBalance;
    int userCount = 0;

    // storage variables
    float highestBalance = 0.0;
    float sumBalance = 0.0;
    int swedishUser = 0;
    bool istherezoomer = false;

    while (cin >> accts[20] >> age) {
        // store user infomration in struct
        accts[userCount].username = name;
        accts[userCount].nationality = nationality;
        accts[userCount].age = age;
        accts[userCount].accountBalance = accountBalance;
        
       //update totals
       sumBalance += accountBalance;
       if(accountBalance > highestBalance) {
        highestBalance = accountBalance;
       } //if there's a swedish person, add to the count
       if(nationality == "Swedish"){
        swedishUser++;
       } //if there's anyone under 21, make true
       if(age < 21) {
        istherezoomer = true;
       }
       
       // add one to total of users
        userCount++;
    }

    //output user information
    cout << "User Information:" << endl;
    
    
    return 0;
};


