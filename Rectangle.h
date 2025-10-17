#pragma once
#include "Pair.h"

class Rectangle
{
    private:
        Pair sides; // композиція — пара чисел (довжина і ширина)

    public:
        Pair getSides() const { return sides; }
        void setSides(const Pair& p) { sides = p; }

        void Init(Pair sides);
        void Read();
        void Display() const;

        double Area() const;
        double Perimeter() const;

        Rectangle();
        Rectangle(double a, double b);
        Rectangle(const Rectangle& r);
        Rectangle& operator=(const Rectangle& r);

        operator string() const;

        friend ostream& operator<<(ostream& out, const Rectangle& r);
        friend istream& operator>>(istream& in, Rectangle& r);

        ~Rectangle();
};

