#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include <string>

using namespace std;


class FoodOrder : public DeliveryOrder {
private:
    string restaurantName;
    int foodCount;

public:
    //constructor should add to parameter string shopName
    FoodOrder(string, string, string, float, string restaurantName);

    //destructor
    ~FoodOrder();

    //functions
    void receipt() const;
    float VIPdiscount() const override;
    void addFood(string mainCourse, int sides, bool soup = false);
};

#endif // FOODORDER_H
