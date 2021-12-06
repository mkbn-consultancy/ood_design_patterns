#pragma once

//forward declaration
class Customer;
class Order;
class Item;

class IVisitor
{
public:
    virtual void visit(CustomersGroup*) = 0;
    virtual void visit(Customer*) = 0;
    virtual void visit(Order*) = 0;
    virtual void visit(Item*) = 0;
};

