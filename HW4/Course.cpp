#include "Course.h"

Course::Course()
{
    student_count = 0;
    student_capacity = 8;
    students = nullptr;
}

Course::Course(const string n, const string c)
{
    name = n;
    code = c;
    student_count = 0;
    student_capacity = 8;
    students = nullptr;
}

Course::Course(const Course& other)
{
    students = new Student [other.student_count];
    for (int i = 0; i < other.student_count; i++)
        students[i] = other.students[i];
    name = other.name;
    code = other.code;
    student_count = other.student_count;
    student_capacity = other.student_capacity;
}

Course& Course::operator=(const Course& other)
{
    Student* temp;
    temp = new Student [other.student_count];
    for (int i = 0; i < other.student_count; i++)
        temp[i] = other.students[i];
    delete [] students;
    students = temp;
    name = other.name;
    code = other.code;
    student_count = other.student_count;
    student_capacity = other.student_capacity;
    return (*this);
}

Course::~Course()
{
    delete [] students;
}
