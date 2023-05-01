#include "Course.h"

Course::Course()
{
    students = nullptr;
    count = 0;
}

Course::Course(const string n, const string c)
{
    name = n;
    code = c;
    count = 0;
    students = new Student [1];
}

Course::Course(const Course& other)
{
    students = new Student [other.count];
    for (int i = 0; i < other.count; i++)
        students[i] = other.students[i];
    name = other.name;
    code = other.code;
    count = other.count;
}

Course& Course::operator=(const Course& other)
{
    Student* temp;
    temp = new Student [other.count];
    for (int i = 0; i < other.count; i++)
        temp[i] = other.students[i];
    delete [] students;
    students = temp;
    name = other.name;
    code = other.code;
    count = other.count;
    return (*this);
}

Course::~Course()
{
    delete [] students;
}
