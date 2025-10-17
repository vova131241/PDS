#include "Course.h"

Course::Course() : name(""), hours(0), students(0), avgGrade(0.0) {}

Course::Course(string name, int hours, int students, double avgGrade)
    : name(name), hours(hours), students(students), avgGrade(avgGrade) {}

Course::Course(const Course& other)
{
    name = other.name;
    hours = other.hours;
    students = other.students;
    avgGrade = other.avgGrade;
}

string Course::getName() const { return name; }
int Course::getHours() const { return hours; }
int Course::getStudents() const { return students; }
double Course::getAvgGrade() const { return avgGrade; }

void Course::setName(string name) { this->name = name; }
void Course::setHours(int hours) { this->hours = hours; }
void Course::setStudents(int students) { this->students = students; }
void Course::setAvgGrade(double avgGrade) { this->avgGrade = avgGrade; }

void Course::Read()
{
    cout << "������ ����� �����: ";
    cin >> name;
    cout << "ʳ������ �����: ";
    cin >> hours;
    cout << "ʳ������ ��������: ";
    cin >> students;
    cout << "������� ���: ";
    cin >> avgGrade;
}

void Course::Display() const
{
    cout << *this << endl;
}

Course::operator string() const
{
    stringstream ss;
    ss << "�����: " << name
        << " | �����: " << hours
        << " | ��������: " << students
        << " | ������� ���: " << avgGrade;
    return ss.str();
}

ostream& operator<<(ostream& out, const Course& c)
{
    out << string(c);
    return out;
}

istream& operator>>(istream& in, Course& c)
{
    cout << "����� �����: ";
    in >> c.name;
    cout << "ʳ������ �����: ";
    in >> c.hours;
    cout << "ʳ������ ��������: ";
    in >> c.students;
    cout << "������� ���: ";
    in >> c.avgGrade;
    return in;
}

