#ifndef _COURSE_H_
# define _COURSE_H_

#include "Student.h"
using namespace std;

class Student;

class Course
{
    private:
        string name;
        string code;
        Student* students;
        int count;

    public:
        Course();
        Course(const string n, const string c);
        Course(const Course& other);
        Course& operator=(const Course& other);
        ~Course();
        inline int get_count() const {return (count);};
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline string get_code() const {return (code);};
        inline void set_code(const string c) {code = c;};
        inline Student* get_students() const {return (students);};

};


#endif