#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Course
{
private:
    string name;
    int hours;
    int students;
    double avgGrade;

public:
    Course();
    Course(string name, int hours, int students, double avgGrade);
    Course(const Course& other);

    string getName() const;
    int getHours() const;
    int getStudents() const;
    double getAvgGrade() const;

    void setName(string name);
    void setHours(int hours);
    void setStudents(int students);
    void setAvgGrade(double avgGrade);

    void Read();
    void Display() const;

    operator string() const;

    friend ostream& operator<<(ostream& out, const Course& c);
    friend istream& operator>>(istream& in, Course& c);
};

