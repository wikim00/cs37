#include "BobaOrder.h"
#include "InvalidInput.h"
#include <iostream>
using namespace std;

BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
}

void BobaOrder::receipt() const {
    DeliveryOrder::receipt(); // Call base class's receipt function
    cout << "\tShop Name: " << shopName << "\n";
    cout << "\tDrinks Count: " << drinksCount << endl;
}

float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10)
        return 0.8;
    else if (drinksCount > 5)
        return 0.9;
    else if (drinksCount > 2)
        return 0.95;
    else
        return 1.0;
}

void BobaOrder::addDrink(string& drink, bool addBoba, int count) {
    // Calculate cost based on drink and whether boba is added
    float drinkCost = 0.0;
    if (drink == "Green Tea Latte")
        drinkCost = 5.8;
    else if (drink == "Brown Sugar Boba Milk")
        drinkCost = 7.8;
    else if (drink == "Brown Sugar Pearl Milk")
        drinkCost = 9.8;
    else
        throw InvalidInput(drink); // Throw InvalidInput exception if drink is not recognized

    // Add cost for boba if requested
    if (addBoba)
        drinkCost += 1.0;

    // Add cost for the specified number of drinks
    drinkCost *= count;

    // Update drinks count and order balance
    drinksCount += count;
    orderBalance += drinkCost;
}
