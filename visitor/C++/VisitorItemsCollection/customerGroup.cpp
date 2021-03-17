#include "customersGroup.h"
#include "ivisitor.h"

void CustomersGroup::accept(IVisitor* p){
    for(auto c : _customersInGroup){
        c.accept(p);
    }
}

void CustomersGroup::addCustomer(const Customer& customer){
    _customersInGroup.push_back(customer);
}