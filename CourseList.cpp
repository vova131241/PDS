#include "CourseList.h"
#include <algorithm>
#include <iostream>
using namespace std;

CourseList::CourseList(int size)
{
    this->size = size;
    courses = new Course[size];
}

CourseList::CourseList(const CourseList& other)
{
    size = other.size;
    courses = new Course[size];
    for (int i = 0; i < size; i++)
        courses[i] = other.courses[i];
}

CourseList::~CourseList()
{
    delete[] courses;
}

void CourseList::ReadAll()
{
    cout << "=== Введення даних курсів ===" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\nКурс #" << i + 1 << ":" << endl;
        courses[i].Read();
    }
}

void CourseList::DisplayAll() const
{
    cout << "\n=== Список курсів ===" << endl;
    for (int i = 0; i < size; i++)
        courses[i].Display();
}

Course CourseList::FindBestAvgGrade() const
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (courses[i].getAvgGrade() > courses[index].getAvgGrade())
            index = i;
    }
    return courses[index];
}

void CourseList::SortByHoursDesc()
{
    sort(courses, courses + size, [](const Course& a, const Course& b)
        { return a.getHours() > b.getHours(); });
}

void CourseList::PrintMoreThan30() const
{
    cout << "\nКурси, де студентів > 30:" << endl;
    for (int i = 0; i < size; i++)
        if (courses[i].getStudents() > 30)
            courses[i].Display();
}
