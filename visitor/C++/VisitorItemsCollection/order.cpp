#include "order.h"
#include "ivisitor.h"

void Order::accept(IVisitor* p){
    p->visit(this);
    for(auto i : _itemsInOrder){
        i.accept(p);
    }
}

void Order::addItem(const std::string& name){
    _itemsInOrder.push_back(std::move(Item(name)));
}