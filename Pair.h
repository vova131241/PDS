#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Pair
{
    private:
        double first;
        double second;

    public:
        double getFirst() const { return first; }
        double getSecond() const { return second; }

        void setFirst(double value) { first = value; }
        void setSecond(double value) { second = value; }

        void Init(double first, double second);
        void Read();
        void Display() const;

        double Product() const; // добуток двох чисел

        Pair();
        Pair(double first, double second);
        Pair(const Pair& p);
        Pair& operator=(const Pair& p);

        operator string() const;

        friend ostream& operator<<(ostream& out, const Pair& p);
        friend istream& operator>>(istream& in, Pair& p);

        ~Pair();
};

