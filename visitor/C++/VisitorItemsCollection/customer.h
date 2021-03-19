#pragma once

#include "ivisitable.h"
#include "nameImpl.h"
#include "order.h"
#include <vector>

// forward declaration
class IVisitor;

class Customer : public NameImpl, public IVisitable
{
public:
    Customer(const std::string& name) : NameImpl(name){}
    virtual void accept(IVisitor*) override;
    void addOrder(const Order& order);

private:
    std::vector<Order> _orders;
};