#pragma once

#include <string>
#include <vector>
#include "visitableImpl.h"
#include "item.h"

class Order : public VisitableImpl
{
public:
    Order(const std::string& name) : VisitableImpl(name){}
    virtual void accept(IVisitor* p) override;
    void addItem(const std::string& name);
private:
    std::vector<Item> _itemsInOrder;
};