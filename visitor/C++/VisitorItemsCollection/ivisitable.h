#pragma once

//forward declaration
class IVisitor;

class IVisitable
{
public:
    virtual void accept(IVisitor*) = 0;
};
