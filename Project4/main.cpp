#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"
#include "DeliveryOrder.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to apply discount based on account status
float applyDiscount(const DeliveryOrder* order, const Account& account) {
    string status = account.getStatus();

    if (status == "Owner") {
        // Apply 90% discount for owner account
        return order->getTotalBalance() * 0.10f;
    } else if (status == "VIP") {
        // Dynamically call VIPdiscount() function if available
        float discount = order->VIPdiscount();
        return order->getTotalBalance() * discount;
    } else {
        // No discount for regular account
        return order->getTotalBalance();
    }
}

int main() {
    // Creating accounts
    const Account stuart("Stuart", "Owner");
    Account kevin("Kevin", "VIP");
    Account bob("Bob");

    // Kevin placing order
    cout << "Kevin is placing order.\n";
    BobaOrder kevinOrder("Kevin", "04/20/2024", "123-456-0000", 10.4, "M Tea");
    try {
        kevinOrder.addDrink("Green Tea Latte");
        kevinOrder.addDrink("Brown Sugar Pearl Milk", 0, false);
        kevinOrder.addDrink("Brown Sugar Boba Milk", 0, false);
        kevinOrder.addDrink("Brown Sugar Boba Milk", 0, false);
        kevinOrder.addDrink("Iron Goddess");
    } catch (const InvalidInput e) {
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    kevinOrder.receipt();
    cout << fixed << setprecision(2);
    cout << "Balance: $" << kevinOrder.getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(&kevinOrder, kevin) << endl << endl;

    // // Stuart placing order
    // cout << "Stuart is placing order.\n";
    // FoodOrder stuartOrder("Stuart", "04/20/2024", "123-456-1111", 25.5, "Tavern Green");
    // try {
    //     stuartOrder.addFood("Thick Cauliflower Steaks", 1, true);
    //     stuartOrder.addFood("Organic Scottish Salmon");
    //     stuartOrder.addFood("Rack of Lamb", 0, true);
    // } catch (const InvalidInput& e) {
    //     cout << "Not serving requested food. Food order ignored.\n\n";
    // }
    // stuartOrder.receipt();
    // cout << "Balance: $" << stuartOrder.getTotalBalance() << endl;
    // cout << "Discounted Balance: $" << applyDiscount(&stuartOrder, stuart) << endl << endl;

    // // Bob placing order
    // cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
    // stuartOrder.receipt();
    // cout << "Balance: $" << stuartOrder.getTotalBalance() << endl;
    // cout << "Discounted Balance: $" << applyDiscount(&stuartOrder, bob) << endl << endl;
    // cout << "Bob upset, cancelling order :(\n\n";

    // // Output total order placed
    // cout << "Total order placed: " << DeliveryOrder::getOrderCount() << ".\n\n";

    return 0;
}