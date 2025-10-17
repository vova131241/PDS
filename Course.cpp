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
    cout << "Введіть назву курсу: ";
    cin >> name;
    cout << "Кількість годин: ";
    cin >> hours;
    cout << "Кількість студентів: ";
    cin >> students;
    cout << "Середній бал: ";
    cin >> avgGrade;
}

void Course::Display() const
{
    cout << *this << endl;
}

Course::operator string() const
{
    stringstream ss;
    ss << "Назва: " << name
        << " | Годин: " << hours
        << " | Студентів: " << students
        << " | Середній бал: " << avgGrade;
    return ss.str();
}

ostream& operator<<(ostream& out, const Course& c)
{
    out << string(c);
    return out;
}

istream& operator>>(istream& in, Course& c)
{
    cout << "Назва курсу: ";
    in >> c.name;
    cout << "Кількість годин: ";
    in >> c.hours;
    cout << "Кількість студентів: ";
    in >> c.students;
    cout << "Середній бал: ";
    in >> c.avgGrade;
    return in;
}

