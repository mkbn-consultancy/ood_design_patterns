#include <iostream>
#include <stdlib.h>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapePainter.h"

IShape* getShape() {
	int i = rand() % 2;
	IShape* result;
	switch (i) {
	case 0: result = new Circle;
		break;
	case 1: result = new Rectangle;
		break;
	}
	return result;
}

int main() {
	IShape* vec[10];
	//init with shapes...
	for (int i = 0; i < 10; ++i) {
		vec[i] = getShape();
	}
	ShapePainter shpPaint;
	for (int i = 0; i < 10; ++i) {
		shpPaint.paint(vec[i]);
	}
	return 0;
}