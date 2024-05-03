#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string username;
    string status;

public:
    //constructor should add to parameter string shopName
    Account(string username, string status = "Regular")
    {
        this->username = username;
        this->status = status;
    };

    //destructor
    ~Account()
    {
        cout << "Account removed. \n";
    }

    //functions
    string getStatus() const
    {
        return status;
    }
};

#endif // ACCOUNT_H
