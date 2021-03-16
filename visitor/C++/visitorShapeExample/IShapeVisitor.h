#pragma once

//forward declaration
class IShape;
class Circle;
class Rectangle;

class IShapeVisitor {
public:
//	virtual void visit(IShape*) = 0;
	virtual void visit(Circle*) = 0;
	virtual void visit(Rectangle*) = 0;
};

