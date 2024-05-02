#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "DeliveryOrder.h"

using namespace std;

class Account {
private:
    string username;
    string status;

public:
    Account(const string& username, const string& status = "Regular");
    ~Account();
    float applyDiscount();
    string getStatus() const;
};

#endif // ACCOUNT_H
