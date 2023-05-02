#include "Student.h"

namespace PA4
{
    /* Student default constructor */
    Student::Student()
    {
        course_count = 0;
        course_capacity = 8;
        not_taken_course_count = 0;
        courses = nullptr;
        courses_not_taken = nullptr;
    }
    
    /*Student constructor*/
    Student::Student(const string n, const unsigned int i)
    {
        name = n;
        id = i;
        course_count = 0;
        course_capacity = 8;
        not_taken_course_count = 0;
        courses = nullptr;
        courses_not_taken = nullptr;
    }

    /*Student copy constructor */
    Student::Student(const Student& other)
    {
        courses = new Course [other.course_count];
        courses_not_taken = new Course [other.not_taken_course_count];
        for (int i = 0; i < other.course_count; i++)
            courses[i] = other.courses[i];
        for (int i = 0; i < other.not_taken_course_count; i++)
            courses_not_taken[i] = other.courses_not_taken[i];
        name = other.name;
        id = other.id;
        course_count = other.course_count;
        course_capacity = other.course_capacity;
        not_taken_course_count = other.not_taken_course_count;
    }

    /* Student assignment operator */
    Student& Student::operator=(const Student& other)
    {
        Course* temp = new Course [other.course_count];
        Course* temp_not_taken = new Course [other.not_taken_course_count];
        for (int i = 0; i < other.course_count; i++)
            temp[i] = other.courses[i];
        for (int i = 0; i < other.not_taken_course_count; i++)
            temp_not_taken[i] = other.courses_not_taken[i];
        delete [] courses;
        delete [] courses_not_taken;
        courses = temp;
        courses_not_taken = temp_not_taken;
        name = other.name;
        id = other.id;
        course_count = other.course_count;
        course_capacity = other.course_capacity;
        not_taken_course_count = other.not_taken_course_count;
        return (*this);
    }

    /* Destructor */
    Student::~Student()
    {
        delete [] courses;
    }

}
