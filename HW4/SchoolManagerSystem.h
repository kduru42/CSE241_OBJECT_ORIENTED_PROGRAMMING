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
        void decide_courses_not_taken(const string name, const unsigned int id);
        void add_selected_student_to_a_course(const string name, const unsigned int id, const int course_num);
        void drop_selected_student_from_a_course(const string name, const unsigned int id, const int course_num);
        void list_cources_that_is_taken(const string name, const unsigned int id);
        void list_students_registered_to_the_selected_course(const string code, const string name);
};


#endif