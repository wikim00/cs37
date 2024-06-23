#include "FoodOrder.h"
#include <iostream>
#include <string>

using namespace std;

//initialize static member counter
int FoodOrder::foodCount = 0;

//constructor definition
FoodOrder::FoodOrder(string name, string date, 
string phone, float miles, string restaurantName)
:DeliveryOrder(name, date, phone, miles, orderBalance)
{
    this->restaurantName = restaurantName;
}

FoodOrder::~FoodOrder()
{
    cout << "FoodOrder destroyed. \n";
}

void FoodOrder::receipt() const 
{
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

void FoodOrder::addFood(string mainCourse, int sides, bool soup) 
{
    float foodCost = 0.0;

    if (mainCourse == "Thick Cauliflower Steaks")
        foodCost = 15;
    else if (mainCourse == "Rack of Lamb")
        foodCost = 38;
    else if (mainCourse == "Organic Scottish Salmon")
        foodCost = 23;
    else if (mainCourse == "Grilled Lobster Risotto")
        foodCost = 46;
    else
        throw InvalidInput(mainCourse);

    // soup cost
    if (soup == true)
        foodCost += 5.0;

    // side cost
    foodCost += sides * 6;

    // update orderBalance
    foodCount += 1;
    orderBalance += foodCost;
}

float FoodOrder::VIPdiscount() const
{
    if (orderBalance > 50)
        return 0.8;
    else if (orderBalance > 30)
        return 0.9;
    else if (orderBalance > 20)
        return 0.95;
    else
        return 1.0;
}