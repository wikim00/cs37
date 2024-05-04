#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include <string>

using namespace std;

// food order public inherit delivery order
class FoodOrder : public DeliveryOrder {
private:
    string restaurantName;
    int static foodCount;

public:
    //constructor should add to parameter string shopName
    FoodOrder(string, string, string, float, string restaurantName);

    //destructor
    ~FoodOrder();

    //functions
    void receipt() const;
    float VIPdiscount() const override;
    void addFood(string mainCourse, int sides = 0, bool soup = false);
};

#endif // FOODORDER_H
