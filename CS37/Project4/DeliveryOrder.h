#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include "InvalidInput.h"
#include <string>
using namespace std;

class DeliveryOrder {
private:
    //private member variables
    string name;
    string date;
    string phone;
    float miles;

    //private static variables
    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;

protected:
    //can be accessed by inherited classes
    float orderBalance;

public:
    //constructor
    DeliveryOrder(string name, string date, string phone, float miles, float orderBalance);

    //destructor
    ~DeliveryOrder();

    //functions
    void receipt() const;
    float getTotalBalance() const;
    static int getOrderCount();
    virtual float VIPdiscount() const = 0;
};

#endif // DELIVERYORDER_H
