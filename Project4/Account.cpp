#include "Account.h"
#include "DeliveryOrder.h"
#include <iostream>

Account::Account(const std::string& username, const std::string& status)
    : username(username), status(status) {}

Account::~Account() {
    std::cout << "Account removed.\n";
}

std::string Account::getStatus() const {
    return status;
}

float applyDiscount(const DeliveryOrder* order, const Account& account) {
    if (account.getStatus() == "Owner") {
        // Apply 90% off for owner
        return order->getTotalBalance() * 0.1;
    } else if (account.getStatus() == "VIP") {
        // Dynamically call VIPdiscount() based on the order
        return order->VIPdiscount() * order->getTotalBalance();
    } else {
        // Regular status, no discount
        return order->getTotalBalance();
    }
}