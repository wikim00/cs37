#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include <string>

using namespace std;

// bobaOrder public inherit DeliveryOrder
class BobaOrder : public DeliveryOrder {
private:
    string shopName;
    int static drinksCount;

public:
    //constructor should add to parameter string shopName
    BobaOrder(string, string, string, float, string shopName);

    //destructor
    ~BobaOrder();

    //functions
    void receipt() const;
    float VIPdiscount() const override;
    void addDrink(string drink, bool addBoba = true, int count = 1);
};

#endif // BOBAORDER_H
