#include <iostream>
#include "CourseList.h"
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CourseList list(3);

    list.ReadAll();

    cout << "\n=== �� ����� ===" << endl;
    list.DisplayAll();

    cout << "\n=== ���� � �������� ������� ����� ===" << endl;
    Course best = list.FindBestAvgGrade();
    cout << best << endl;

    cout << "\n=== �����, ���������� �� ������� ����� (���������) ===" << endl;
    list.SortByHoursDesc();
    list.DisplayAll();

    list.PrintMoreThan30();

    return 0;
}
