//
// Created by admin on 2022/2/3.
//

#ifndef COMP335_P_ORDERS_H
#define COMP335_P_ORDERS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Order{
public:
    Order(int Id);
    int orderId;
    int getId();
};

class OrderList{
public:
    OrderList();
    void add(Order* order);
private:
    vector<Order>* orderList;

};
#endif //COMP335_P_ORDERS_H