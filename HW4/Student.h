#ifndef _STUDENT_H_
# define _STUDENT_H_

#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class Course;

class Student
{
    private:
        string name;
        unsigned int id;
        Course *courses;
        int count;

    public:
        Student();
        Student(const string n, const unsigned int i);
        ~Student();
        Student(const Student& other);
        Student& operator=(const Student& other);
        inline int get_count() const {return (count);};
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline unsigned int get_id() const {return (id);};
        inline void set_id(const unsigned int i) {id = i;};
        inline Course* get_courses() const {return (courses);};

};



#endif