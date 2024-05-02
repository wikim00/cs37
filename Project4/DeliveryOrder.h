#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>
using namespace std;

class DeliveryOrder {
private:
    string name;
    string date;
    string phone;
    float miles;

    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;

public:
    //constructor
    DeliveryOrder(string name, string date, 
    string phone, float miles, float orderBalance);
    virtual ~DeliveryOrder(); // virtual destructor

    void receipt() const;
    float getTotalBalance() const;
    static int getOrderCount();
    virtual float VIPdiscount() const;

    float orderBalance;
};

#endif // DELIVERYORDER_H
