#pragma once

#include "visitableImpl.h"
#include <string>

class Item : public VisitableImpl
{
public:
    Item(const std::string& name) : VisitableImpl(name) {}
    virtual void accept(IVisitor*) override;
};