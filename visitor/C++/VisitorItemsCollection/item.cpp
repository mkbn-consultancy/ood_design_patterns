#include "item.h"
#include "ivisitor.h"

void Item::accept(IVisitor* p){
    p->visit(this);
}

