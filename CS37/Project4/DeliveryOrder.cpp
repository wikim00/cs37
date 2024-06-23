#include "DeliveryOrder.h" // Include the header file where the class is declared
#include <iostream>

using namespace std;

//initialize static member variables
const float DeliveryOrder::taxRate = 0.09;
const float DeliveryOrder::deliveryRate = 2.0;
int DeliveryOrder::orderCount = 0;

//constructor definition
DeliveryOrder::DeliveryOrder(string name, string date, string phone, float miles, float orderBalance)
{
    this->name = name;
    this->date = date;
    this->phone = phone;
    this->miles = miles;
    orderBalance = 0;
    orderCount++;
}

//destructor definition
DeliveryOrder::~DeliveryOrder() {
    // Optionally print a message when object is destroyed
    cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}

float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
}

int DeliveryOrder::getOrderCount() {
    return orderCount;
}
