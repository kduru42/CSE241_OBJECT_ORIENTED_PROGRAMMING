#ifndef _SCHOOL_MANAGER_SYSTEM_H_
# define _SCHOOL_MANAGER_SYSTEM_H_

#include "Student.h"
#include "Course.h"


class SchoolManagerSystem
{
    private:
        Course* courses;
        Student* students;
        int student_count;
        int course_count;
        int student_capacity;
        int course_capacity;
    
    public:
        SchoolManagerSystem();
        SchoolManagerSystem(const SchoolManagerSystem& other);
        SchoolManagerSystem& operator=(const SchoolManagerSystem& other);
        ~SchoolManagerSystem();
        inline int get_student_count() const {return (student_count);};
        inline int get_course_count() const {return (course_count);};
        inline int get_student_capacity() const {return (student_capacity);};
        inline int get_course_capacity() const {return (course_capacity);};
        inline Course* get_courses() const {return(courses);};
        inline Student* get_students() const {return (students);};
        void add_student(const string name, const unsigned int id);
        void delete_student(const string name, const unsigned int id);
        void list_all_students() const;
        void add_course(const string code, const string name);
        void delete_course(const string code, const string name);
        void list_all_courses() const;
};


#endif