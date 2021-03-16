#include "ShapePainter.h"
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

void ShapePainter::paint(IShape* p) {
	p->accept(this);
}
void ShapePainter::visit(Circle*) {
	std::cout << "Painting a Circle...\n";
}
void ShapePainter::visit(Rectangle*) {
	std::cout << "Painting a Rectangle...\n";
}
