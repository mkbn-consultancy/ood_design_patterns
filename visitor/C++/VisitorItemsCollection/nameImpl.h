#pragma once

// #include "ivisitable.h"
#include <string>

class NameImpl 
{
public:
    NameImpl(const std::string& name) : _name(name) {}
    void setName(const std::string& name) { _name = name; }
    std::string getName() const { return _name; }
protected:
    std::string _name;
};