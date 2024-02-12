#include <iostream>
#include <string>
using namespace std;

//structure creates an object i guess to store information in an
// organized fashion
struct userAccount {
    /* structure to store info on user*/
    string username;
    string nationality;
    int age;
    //initialize float variable to track the highest balance
    float highestBalance = 0.0
};

int main() {
    // Create an array of user struct holding up to 20 accounts
    userAccount accts[20];

    // instruction
    cout << "Please enter information to database in the format of <username> 
    <nationality> <age> <accountBalance>, separated each user by a newline:" << endl;

    // read in user name and age into struct
    string username;
    int age;
    int count = 0;
    while (cin >> username >> age) {
        userAccount user;
        user.username = username;
        user.age = age;
        accts[count] = age;
        count++;
    }

    //output user information
    return 0;
};
