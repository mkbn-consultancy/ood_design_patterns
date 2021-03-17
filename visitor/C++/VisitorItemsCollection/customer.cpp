#include "customer.h"
#include "ivisitor.h"

void Customer::accept(IVisitor* p){
    p->visit(this); 
    for(auto o : _orders){
        o.accept(p);
    }
}

void Customer::addOrder(const Order& order){
    _orders.push_back(order);
}