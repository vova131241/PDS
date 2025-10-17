#pragma once
#include "Course.h"

class CourseList
{
    private:
        int size;
        Course* courses;

    public:
        CourseList(int size = 7);
        CourseList(const CourseList& other);
        ~CourseList();

        void ReadAll();
        void DisplayAll() const;

        Course FindBestAvgGrade() const;
        void SortByHoursDesc();
        void PrintMoreThan30() const;
};


