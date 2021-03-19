#pragma once

#include <string>
#include <vector>
#include "ivisitable.h"
#include "nameImpl.h"
#include "item.h"

class IVisitor;

class Order : public NameImpl, public IVisitable
{
public:
    Order(const std::string& name) : NameImpl(name){}
 
    virtual void accept(IVisitor* p) override;

    void addItem(const std::string& name);
private:
    std::vector<Item> _itemsInOrder;
};