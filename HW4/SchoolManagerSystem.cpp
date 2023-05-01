#include "SchoolManagerSystem.h"

SchoolManagerSystem::SchoolManagerSystem()
{
    student_count = 0;
    course_count = 0;
    student_capacity = 8;
    course_capacity = 8;
    students = new Student [student_capacity];
    courses = new Course [course_capacity];
}

SchoolManagerSystem::SchoolManagerSystem(const SchoolManagerSystem& other)
{
    students = new Student [other.student_capacity];
    courses = new Course [other.course_capacity];
    for (int i = 0; i < other.student_count; i++)
        students[i] = other.students[i];
    for (int i = 0; i < other.course_count; i++)
        courses[i] = other.courses[i];
    student_count = other.student_count;
    course_count = other.course_count;
    student_capacity = other.student_capacity;
    course_capacity = other.course_capacity;
}

SchoolManagerSystem& SchoolManagerSystem::operator=(const SchoolManagerSystem& other)
{
    Student* temp_students;
    Course* temp_courses;
    temp_students = new Student [other.student_capacity];
    temp_courses = new Course [other.course_capacity];
    for (int i = 0; i < other.student_count; i++)
        temp_students[i] = other.students[i];
    for (int i = 0; i < other.course_count; i++)
        temp_courses[i] = other.courses[i];
    delete [] students;
    delete [] courses;
    students = temp_students;
    courses = temp_courses;
    student_count = other.student_count;
    course_count = other.course_count;
    student_capacity = other.student_capacity;
    course_capacity = other.course_capacity;
    return (*this);
}


SchoolManagerSystem::~SchoolManagerSystem()
{
    delete [] courses;
    delete [] students;
}

void SchoolManagerSystem::add_student(const string name, const unsigned int id)
{
    if (student_count == student_capacity)
    {
        Student* temp = new Student [student_capacity * 2];
        for (int i = 0; i < student_count; i++)
            temp[i] = students[i];
        temp[student_count] = Student(name, id);
        delete [] students;
        students = temp;
        student_count++;
        student_capacity *= 2;
    }
    else
    {
        students[student_count] = Student(name, id);
        student_count++;
    }
}

void SchoolManagerSystem::delete_student(const string name, const unsigned int id)
{
    if (student_count < student_capacity / 4) // shrink_to_fit
    {
        Student* temp = new Student [student_capacity / 2];
        int j = 0;
        for (int i = 0; i < student_count; i++)
        {
            if (students[i].get_name() != name && students[i].get_id() != id)
            {
                temp[j] = students[i];
                j++;
            }
        }
        delete [] students;
        students = temp;
        student_count--;
        student_capacity /= 2;
    }
    else
    {
        int index = 0;
        while (students[index].get_name() != name && students[index].get_id() != id)
            index++;
        for (int i = index + 1; i < student_count; i++)
            students[i - 1] = students[i];
        student_count--;
    }
}

void SchoolManagerSystem::list_all_students() const
{
    for (int i = 0; i < student_count; i++)
        cout << i + 1 << " " << students[i].get_name() << " " << students[i].get_id() << endl;   
}

void SchoolManagerSystem::add_course(const string code, const string name)
{
    if (course_count == course_capacity)
    {
        Course* temp = new Course [course_capacity * 2];
        for (int i = 0; i < course_count; i++)
            temp[i] = courses[i];
        temp[course_count] = Course(name, code);
        delete [] courses;
        courses = temp;
        course_count++;
        course_capacity *= 2;
    }
    else
    {
        courses[course_count] = Course(name, code);
        course_count++;
    }
}

void SchoolManagerSystem::delete_course(const string code, const string name)
{
    if (course_count < course_capacity / 4) // shrink_to_fit
    {
        Course* temp = new Course [course_capacity / 2];
        int j = 0;
        for (int i = 0; i < course_count; i++)
        {
            if (courses[i].get_name() != name && courses[i].get_code() != code)
            {
                temp[j] = courses[i];
                j++;
            }
        }
        delete [] courses;
        courses = temp;
        course_count--;
        course_capacity /= 2;
    }
    else
    {
        int index = 0;
        while (courses[index].get_name() != name && courses[index].get_code() != code)
            index++;
        for (int i = index + 1; i < course_count; i++)
            courses[i - 1] = courses[i];
        course_count--;
    }
} 

void SchoolManagerSystem::list_all_courses() const
{
    for (int i = 0; i < course_count; i++)
        cout << i + 1 << " " << courses[i].get_code() << " " << courses[i].get_name() << endl;   
}

