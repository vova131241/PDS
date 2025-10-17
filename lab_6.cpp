#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Pair p1(4, 7);
    Rectangle r1;
    r1.Init(p1);

    cout << "Initial rectangle:" << endl;
    r1.Display();

    Rectangle r2;
    cin >> r2;
    cout << endl << "You entered:" << endl;
    cout << r2 << endl;

    return 0;
}