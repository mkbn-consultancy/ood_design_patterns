#pragma once

#include "visitableImpl.h"
#include "order.h"
#include <vector>

// forward declaration
class IVisitor;

class Customer : public VisitableImpl
{
public:
    Customer(const std::string& name) : VisitableImpl(name){}
    virtual void accept(IVisitor*) override;
    void addOrder(const Order& order);

private:
    std::vector<Order> _orders;
};