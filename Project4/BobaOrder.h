#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include <string>

using namespace std;

class BobaOrder : public DeliveryOrder {
private:
    string shopName;
    int drinksCount;

public:
    BobaOrder(const string& name, const string& date, 
    const string& phone, float miles, const string& shopName);

    ~BobaOrder();

    void receipt() const;
    float VIPdiscount() const override;
    void addDrink(string& drink, bool addBoba = true, int count = 1);
};

#endif // BOBAORDER_H
