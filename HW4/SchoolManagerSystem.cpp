#include "SchoolManagerSystem.h"

SchoolManagerSystem::SchoolManagerSystem()
{
    student_count = 0;
    course_count = 0;
    student_capacity = 8;
    course_capacity = 8;
    students = new Student [8];
    courses = new Course [8];
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

void SchoolManagerSystem::decide_courses_not_taken(const string name, const unsigned int id)
{
    int index = 0;
    int ioc = 0; // index of count
    int how_many = 0; // how many courses that is taken
    while (students[index].get_name() != name && students[index].get_id() != id)
        index++;
    for (int i = 0; i < course_count; i++)
    {
        for (int j = 0; j < students[index].get_count(); j++)
        {
            if (students[index].get_courses()[j].get_code() == courses[i].get_code() 
                    && students[index].get_courses()[j].get_name() == courses[i].get_name())
            {
                how_many++;
                break;
            }
        }
    }
    if (how_many == 0)
    {
        students[index].get_courses_not_taken() = new Course [course_count - how_many];
        students[index].get_not_taken_count() = course_count - how_many;
    }
    for (int i = 0; i < course_count; i++)
    {
        int flag = 0;
        for (int j = 0; j < students[index].get_count(); j++)
        {
            if (students[index].get_courses()[j].get_code() == courses[i].get_code() 
                    && students[index].get_courses()[j].get_name() == courses[i].get_name())
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            students[index].get_courses_not_taken()[ioc] = courses[i];
            ioc++;
        }
    }
    students[index].get_not_taken_count() = ioc;
    cout << "0 up\n";
    for (int i = 0; i < ioc; i++)
        cout << i + 1 << " " << students[index].get_courses_not_taken()[i].get_code() << " " << students[index].get_courses_not_taken()[i].get_name() << endl;
}

void SchoolManagerSystem::add_selected_student_to_a_course(const string name, const unsigned int id, const int course_num)
{
    int index = 0;
    while (students[index].get_name() != name && students[index].get_id() != id)
        index++;
    int student_capa = students[index].get_capacity();
    int student_size = students[index].get_count();
    int course_capa = courses[course_num - 1].get_capacity();
    int course_size = courses[course_num - 1].get_count();
    if (student_size == 0)
        students[index].get_courses() = new Course [student_capa];
    if (course_size == 0)
        courses[course_num - 1].get_students() = new Student [course_capa];
    if (student_capa == student_size)
    {
        Course *temp = new Course [student_capa * 2];
        for (int i = 0; i < student_size; i++)
            temp[i] = students[index].get_courses()[i];
        temp[student_size] = students[index].get_courses_not_taken()[course_num - 1];
        delete [] students[index].get_courses();
        students[index].get_courses() = temp;
        students[index].get_count()++;
        students[index].get_capacity() *= 2;  
    }
    else
    {
        students[index].get_courses()[student_size] = students[index].get_courses_not_taken()[course_num - 1];
        students[index].get_count()++;
    }
    
    if (course_capa == course_size)
    {
        Student *temp = new Student [course_capa * 2];
        for (int i = 0; i < course_size; i++)
            temp[i] = courses[course_num - 1].get_students()[i];
        temp[course_size] = Student(name, id);
        delete [] courses[course_num].get_students();
        courses[course_num - 1].get_students() = temp;
        courses[course_num - 1].get_students()++;
        courses[course_num - 1].get_capacity() *= 2;  
    }
    else
    {
        courses[course_num - 1].get_students()[course_size] = Student(name, id); 
        courses[course_num - 1].get_count()++;
    }
}

void SchoolManagerSystem::drop_selected_student_from_a_course(const string name, const unsigned int id, const int course_num)
{
    int index = 0;
    while (students[index].get_name() != name && students[index].get_id() != id)
        index++;
    int student_capa = students[index].get_capacity();
    int student_size = students[index].get_count();
    int course_capa = courses[course_num - 1].get_capacity();
    int course_size = courses[course_num - 1].get_count();
    if (student_size < student_capa / 4)
    {
        Course *temp = new Course [student_capa / 2];
        int j = 0;
        for (int i = 0; i < student_size; i++)
        {
            if (students[index].get_courses()[i].get_code() != courses[course_num - 1].get_code()
                    && students[index].get_courses()[i].get_name() != courses[course_num - 1].get_name())
            {
                temp[j] = students[index].get_courses()[i];
                j++;
            }
        }
        delete [] students[index].get_courses();
        students[index].get_courses() = temp;
        students[index].get_count()--;
        students[index].get_capacity() /= 2;
    }
    else
    {
        int i = 0;
        while (students[index].get_courses()[i].get_code() != courses[course_num - 1].get_code()
                    && students[index].get_courses()[i].get_name() != courses[course_num - 1].get_name())
            i++;
        for (int j = i + 1; j < student_count; j++)
            students[index].get_courses()[j - 1] = students[index].get_courses()[j];
        students[index].get_count()--;
    }

    if (course_size < course_capa / 4)
    {
        Student *temp = new Student [course_capa / 2];
        int j = 0;
        for (int i = 0; i < course_size; i++)
        {
            if (courses[course_num - 1].get_students()[i].get_name() != students[index].get_name()
                    && courses[course_num - 1].get_students()[i].get_id() != students[index].get_id())
            {
                temp[j] = courses[course_num - 1].get_students()[i];
                j++;
            }
        }
        delete [] courses[course_num - 1].get_students();
        courses[course_num - 1].get_students() = temp;
        courses[course_num - 1].get_count()--;
        courses[course_num - 1].get_capacity() /= 2;
    }
    else
    {
        int i = 0;
        while (courses[course_num - 1].get_students()[i].get_name() != name
                    && courses[course_num - 1].get_students()[i].get_id() != id)
            i++;
        for (int j = i + 1; j < student_count; j++)
            courses[course_num - 1].get_students()[j - 1] = courses[course_num - 1].get_students()[j];
        courses[course_num - 1].get_count()--;
    }
}


void SchoolManagerSystem::list_students_registered_to_the_selected_course(const string code, const string name)
{
    int index = 0;
    while (courses[index].get_code() != code && courses[index].get_name() != name)
        index++;
    for (int i = 0; i < courses[index].get_count(); i++)
    {
        cout << i + 1 << " " << courses[index].get_students()[i].get_name() << " " << courses[index].get_students()[i].get_id() << endl;
    }
}


void SchoolManagerSystem::list_cources_that_is_taken(const string name, const unsigned int id)
{
    int index = 0;
    while (students[index].get_name() != name && students[index].get_id() != id)
        index++;
    cout << "0 up\n";
    for (int i = 0; i < students[index].get_count(); i++)
        cout << i + 1 << students[index].get_courses()[i].get_code() << " " << students[index].get_courses()[i].get_name() << endl;
}
