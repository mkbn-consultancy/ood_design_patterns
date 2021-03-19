#pragma once

#include "ivisitable.h"
#include "nameImpl.h"
#include <string>

//forward declaration
class IVisitor;

class Item : public NameImpl, public IVisitable
{
public:
    Item(const std::string& name) : NameImpl(name) {}

    virtual void accept(IVisitor*) override;
};