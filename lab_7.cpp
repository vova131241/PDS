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

    cout << "\n=== Усі курси ===" << endl;
    list.DisplayAll();

    cout << "\n=== Курс з найвищим середнім балом ===" << endl;
    Course best = list.FindBestAvgGrade();
    cout << best << endl;

    cout << "\n=== Курси, відсортовані за кількістю годин (спаданням) ===" << endl;
    list.SortByHoursDesc();
    list.DisplayAll();

    list.PrintMoreThan30();

    return 0;
}
