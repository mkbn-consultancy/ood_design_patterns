#pragma once

//forward declaration
class IShapeVisitor;

class IShape {
public:
	virtual void accept(IShapeVisitor*) = 0;
};
