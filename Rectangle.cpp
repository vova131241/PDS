#include "Rectangle.h"
#include <sstream>

void Rectangle::Init(Pair sides)
{
    this->sides = sides;
}

void Rectangle::Read()
{
    cout << "Enter rectangle sides:" << endl;
    sides.Read();
}

void Rectangle::Display() const
{
    cout << "Rectangle sides:" << endl;
    sides.Display();
    cout << "Perimeter = " << Perimeter() << endl;
    cout << "Area = " << Area() << endl;
}

double Rectangle::Area() const
{
    return sides.getFirst() * sides.getSecond();
}

double Rectangle::Perimeter() const
{
    return 2 * (sides.getFirst() + sides.getSecond());
}

Rectangle::Rectangle() : sides(0, 0) {}

Rectangle::Rectangle(double a, double b) : sides(a, b) {}

Rectangle::Rectangle(const Rectangle& r) : sides(r.sides) {}

Rectangle& Rectangle::operator=(const Rectangle& r)
{
    if (this != &r)
        sides = r.sides;
    return *this;
}

Rectangle::operator string() const
{
    stringstream ss;
    ss << "Rectangle: " << string(sides)
        << ", Perimeter = " << Perimeter()
        << ", Area = " << Area();
    return ss.str();
}

ostream& operator<<(ostream& out, const Rectangle& r)
{
    out << string(r);
    return out;
}

istream& operator>>(istream& in, Rectangle& r)
{
    cout << "Enter rectangle sides:" << endl;
    in >> r.sides;
    return in;
}

Rectangle::~Rectangle() {}
