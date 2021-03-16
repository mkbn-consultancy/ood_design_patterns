#pragma once
#include "IShapeVisitor.h"

//forward declarations
class IShape;
class Circle;
class Rectangle;

class ShapePainter : public IShapeVisitor {
public:
	virtual void paint(IShape* p);
	virtual void visit(Circle*);
	virtual void visit(Rectangle*);
};
