#include "Student.h"

Student::Student()
{
    courses = nullptr;
    count = 0;
}

Student::Student(const string n, const unsigned int i)
{
    name = n;
    id = i;
    count = 0;
    courses = nullptr;
}

Student::Student(const Student& other)
{
    courses = new Course [other.count];
    for (int i = 0; i < other.count; i++)
        courses[i] = other.courses[i];
    name = other.name;
    id = other.id;
    count = other.count;
}

Student& Student::operator=(const Student& other)
{
    Course* temp;
    temp = new Course [other.count];
    for (int i = 0; i < other.count; i++)
        temp[i] = other.courses[i];
    delete [] courses;
    courses = temp;
    name = other.name;
    id = other.id;
    count = other.count;
    return (*this);
}


Student::~Student()
{
    delete [] courses;
}