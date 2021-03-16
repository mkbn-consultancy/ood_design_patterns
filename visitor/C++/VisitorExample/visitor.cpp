#include <iostream>

// The concrete shapes
struct Square;
struct Circle;

#define M_PI 3.14

// The visitor interface
struct IShapeVisitor
{
    virtual ~IShapeVisitor() = default;
    virtual void visit(const Square&) = 0;
    virtual void visit(const Circle&) = 0;
};

// The shape interface
struct IShape
{
    virtual ~IShape() = default;

    virtual void accept(IShapeVisitor&) const = 0;
};

struct Point {
    double x;
    double y;
};

struct Circle : IShape
{
    Circle(const Point& center, double radius) : center(center), radius(radius) {}

    // Each shape has to implement this method the same way
    void accept(IShapeVisitor& visitor) const override { visitor.visit(*this); }

    Point center;
    double radius;
};

struct Square : IShape
{
    Square(const Point& topLeft, double sideLength) :
         topLeft(topLeft), sideLength(sideLength)
    {}

    // Each shape has to implement this method the same way
    void accept(IShapeVisitor& visitor) const override { visitor.visit(*this); }

    Point topLeft;
    double sideLength;
};

struct ShapePrinter : IShapeVisitor
{
    void visit(const Square&) override { std::cout << "Square"; }
    void visit(const Circle&) override { std::cout << "Circle"; }
};

struct ShapeAreaComputer : IShapeVisitor
{
    void visit(const Square& square) override
    {
        area = square.sideLength * square.sideLength;
    }

    void visit(const Circle& circle) override
    {
         area = M_PI * circle.radius * circle.radius;
    }

    double area = 0;
};

struct ShapePerimeterComputer : IShapeVisitor
{
    void visit(const Square& square) override { perimeter = 4.0 * square.sideLength; }
    void visit(const Circle& circle) override { perimeter = 2.0 * M_PI * circle.radius; }

    double perimeter = 0.;
};

int main(){
	const Square square = {{-1.0, -1.0}, 2.0};
	const Circle circle{{0.0, 0.0}, 1.0};
	const IShape* shapes[2] = {&square, &circle};

	ShapePrinter shapePrinter;
	ShapeAreaComputer shapeAreaComputer;
	ShapePerimeterComputer shapePerimeterComputer;

	for (const auto* shape : shapes) {
		shape->accept(shapePrinter);
		std::cout << " has an area of ";
		// result will be stored in shapeAreaComputer.area
		shape->accept(shapeAreaComputer);

		// result will be stored in shapePerimeterComputer.perimeter
		shape->accept(shapePerimeterComputer);

		std::cout << shapeAreaComputer.area
			<< ", and a perimeter of "
			<< shapePerimeterComputer.perimeter
			<< std::endl;
		std::cout << "------------------\n";
	}
}