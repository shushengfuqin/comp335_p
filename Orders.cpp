#include "Orders.h"

Order::Order(int Id){
    orderId=Id;
}

int Order::getId() {
    return orderId;
}

OrderList::OrderList() {
    orderList=new vector<Order>;
}

void OrderList::add(Order* order){
    orderList->push_back(*order);
    cout << '\n'<< "Order "<<order->getId()<<"has been added"<<'\n';

}