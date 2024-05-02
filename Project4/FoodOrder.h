#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>
#include <stdexcept>

class FoodOrder : public DeliveryOrder {
private:
    string restaurantName;
    int foodCount;

public:
    FoodOrder(const string& name, const string& date, const string& phone, float miles, const string& restaurantName);
    ~FoodOrder();

    void receipt() const;
    float VIPdiscount() const override;
    void addFood(const string& meal, int sides = 0, bool addSoup = false);
};

#endif // FOODORDER_H
