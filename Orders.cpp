//
// Created by admin on 2022/2/3.
//

#include "Orders.h"
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;
using namespace std;


Orders::Orders() =default;
Orders::Orders(int orderId,string orderName,string orderContent) :
        id(orderId), name(orderName),content(orderContent)
{
}
Orders::~Orders() = default;


// Bomb class

Bomb::Bomb(int orderId,string orderName,string orderContent) :
        id(orderId), name(orderName),content(orderContent)
{
}
Bomb::~Bomb() {};


string Bomb::BombName(){
    return "Bomb";
}
bool Bomb::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Bomb::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}


// deploy class

Deploy::Deploy(int orderId,string orderName,string orderContent) :
        id(orderId), name(orderName),content(orderContent)
{
}
Deploy::~Deploy() = default;


string Deploy::DeployName(){
    return "Deploy";
}
bool Deploy::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Deploy::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Advance class
Advance::Advance( int orderId, string orderName, string orderContent) :
        id(orderId), name(orderName), content(orderContent)
{
}
Advance::~Advance() =default;
string Advance::AdvanceName()  {
    return "Advance";
}
bool Advance::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Advance::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Blockade class
Blockade::Blockade(int orderId, string orderName, string orderContent):
id(orderId), name(orderName), content(orderContent)
{

}
Blockade::~Blockade() = default;
string Blockade::BlockadeName(){
    return "Blockade";
}
bool Blockade::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Blockade::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Airlift class
Airlift::Airlift(int orderId, string orderName, string orderContent):
id(orderId), name(orderName), content(orderContent)
{
}
Airlift::~Airlift() = default;;
string Airlift::AirliftName() {
    return "Airlift";
}
bool Airlift::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Airlift::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

//Negotiate class

Negotiate::Negotiate( int orderId, string orderName, string orderContent) :
        id(orderId), name(orderName), content(orderContent)
{
}
Negotiate::~Negotiate() = default;;
string Negotiate::NegotiateName() {
    return "Negotiate";
}
bool Negotiate::validate(int i){
    if(i == 1){
        return true;
    }
    else {
        return false;
    }
}

void Negotiate::execute(string i) {
    if(i == "valide"){
        cout << "It is validated and going to be executed\n";
    }
}

Orderslist::Orderslist(int length){
   length=orderlist.size();

}


Orderslist::~Orderslist() =default;

void Orderslist::addOrder(Orders order) {
    orderlist.push_back(order);
}


void Orderslist::displayList( )
{
    list <Orders>::iterator it;
    for (it = orderlist.begin( ); it != orderlist.end( ); it++) {
        cout << it->id << "\n";
      /*  cout << it->name << endl;
        cout << it->content << endl;*/
    }
}

/*
list<Orders> Orderslist::getList(){

    return Orderslist::orderlist;
};
*/





bool Orderslist::remove(list<Orders> l, int postion) {
    cout << "List before deleting first element: ";
    for (auto itr = l.begin();
         itr != l.end(); itr++) {
        cout << itr->id << " "<<itr->name<<endl;
    }
    list<Orders>::iterator itr = l.begin();
    for(int i = 0; i<l.size();i++){
        int num =0;
        if(num = postion){
            l.erase(itr);
            return true;
        }
        num++;
        itr++;
    }
    cout << "List after deleting first element: ";
    for (auto itr = l.begin();
         itr != l.end(); itr++) {
        cout << itr->id << " "<<itr->name<<endl;
    }


    return false;


}