#include "BobaOrder.h"
#include <iostream>
#include <string>

using namespace std;

//initialize static member varibale
int BobaOrder::drinksCount = 0;

//constructor definition
BobaOrder::BobaOrder(string name, string date, 
string phone, float miles, string shopName)
:DeliveryOrder(name, date, phone,miles, orderBalance)
{
    this->shopName = shopName;
}

//destructor definition
BobaOrder::~BobaOrder() 
{
    cout << "BobaOrder destroyed.\n";
}

void BobaOrder::receipt() const 
{
    // use DeliveryOrder Function
    DeliveryOrder::receipt();
    drinksCount++;
    cout << "\tDrinks Count: " << drinksCount << endl;
}

//unfinished function
void BobaOrder::addDrink(string drink, bool addBoba, int count) {
    // Calculate cost based on drink type
    float drinkCost = 0.0;
    if (drink == "Green Tea Latte")
        drinkCost = 5.8;
    else if (drink == "Brown Sugar Boba Milk")
        drinkCost = 7.8;
    else if (drink == "Brown Sugar Pearl Milk")
        drinkCost = 9.8;
    else
        throw InvalidInput(drink); // Throw InvalidInput exception if drink is not recognized

    // Add cost for boba
    if (addBoba == true)
        drinkCost += 1.0;
    else
        drinkCost;

    // Add cost for the specified number of drinks
    drinkCost *= count;

    // Update drinks count and order balance
    drinksCount += count;
    orderBalance += drinkCost;
}

float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10) {
        return 0.8; // 20% discount
    } else if (drinksCount > 5) {
        return 0.9; // 10% discount
    } else if (drinksCount > 2) {
        return 0.95; // 5% discount
    } else {
        return 1.0; // No discount
    }
}

