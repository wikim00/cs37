#include "FoodOrder.h"
#include <iostream>
using namespace std;

FoodOrder::FoodOrder(const string& name, const string& date, const string& phone, float miles, const string& restaurantName)
    : DeliveryOrder(name, date, phone, miles, orderBalance), restaurantName(restaurantName), foodCount(0) {}

FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}

void FoodOrder::receipt() const {
    DeliveryOrder::receipt(); // Call base class's receipt function
    cout << "\tRestaurant Name: " << restaurantName << "\n";
    cout << "\tFood Count: " << foodCount << endl;
}

float FoodOrder::VIPdiscount() const {
    if (orderBalance > 50)
        return 0.8;
    else if (orderBalance > 30)
        return 0.9;
    else if (orderBalance > 20)
        return 0.95;
    else
        return 1.0;
}

void FoodOrder::addFood(const string& meal, int sides, bool addSoup) {
    float mealCost = 0.0;
    if (meal == "Thick Cauliflower Steaks")
        mealCost = 15.0;
    else if (meal == "Rack of Lamb")
        mealCost = 38.0;
    else if (meal == "Organic Scottish Salmon")
        mealCost = 23.0;
    else if (meal == "Grilled Lobster Risotto")
        mealCost = 46.0;
    else
        throw InvalidInput(meal); // Throw I
}