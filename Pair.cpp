#include "Pair.h"

void Pair::Init(double first, double second)
{
    this->first = first;
    this->second = second;
}

void Pair::Read()
{
    cout << "Enter first number: ";
    cin >> first;
    cout << "Enter second number: ";
    cin >> second;
}

void Pair::Display() const
{
    cout << "First = " << first << ", Second = " << second << endl;
}

double Pair::Product() const
{
    return first * second;
}

Pair::Pair() : first(0), second(0) {}

Pair::Pair(double first, double second) : first(first), second(second) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

Pair& Pair::operator=(const Pair& p)
{
    if (this != &p)
    {
        first = p.first;
        second = p.second;
    }
    return *this;
}

Pair::operator string() const
{
    stringstream ss;
    ss << "First = " << first << ", Second = " << second;
    return ss.str();
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << string(p);
    return out;
}

istream& operator>>(istream& in, Pair& p)
{
    cout << "Enter first: ";
    in >> p.first;
    cout << "Enter second: ";
    in >> p.second;
    return in;
}

Pair::~Pair() {}
