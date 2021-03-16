#pragma once
#include "IShape.h"
#include "IShapeVisitor.h"

class Circle : public IShape {
public:
	virtual void accept(IShapeVisitor* p) {
		p->visit(this);
	}
};
