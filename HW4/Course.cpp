#include "Course.h"

namespace PA4
{
    /* Course default constructor */
    Course::Course()
    {
        student_count = 0;
        student_capacity = 8; // capacity of the array is set to 8 at first
        students = nullptr;
    }

    /* Course constructor */
    Course::Course(const string n, const string c)
    {
        name = n;
        code = c;
        student_count = 0;
        student_capacity = 8;
        students = nullptr;
    }

    /* Course copy constructor */
    Course::Course(const Course& other)
    {
        students = new Student [other.student_count];
        for (int i = 0; i < other.student_count; i++) // copying elements from other object
            students[i] = other.students[i];
        name = other.name;
        code = other.code;
        student_count = other.student_count;
        student_capacity = other.student_capacity;
    }

    /* Course assignment operator */
    Course& Course::operator=(const Course& other)
    {
        Student* temp; // temp array to copy
        temp = new Student [other.student_count];
        for (int i = 0; i < other.student_count; i++) // copying elements
            temp[i] = other.students[i];
        delete [] students; // deleting old memory
        students = temp;
        name = other.name;
        code = other.code;
        student_count = other.student_count;
        student_capacity = other.student_capacity;
        return (*this);
    }

    /* Course destructor */
    Course::~Course()
    {
        delete [] students;
    }
}
