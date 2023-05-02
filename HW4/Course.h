#ifndef _COURSE_H_
# define _COURSE_H_

#include "Student.h"
using namespace std;

namespace PA4
{
    class Student;

    class Course
    {
        private:
            string name;
            string code;
            Student* students;
            int student_count;
            int student_capacity;

        public:
            Course();
            Course(const string n, const string c);
            Course(const Course& other);
            Course& operator=(const Course& other);
            ~Course();
            inline int &get_count() {return (student_count);};
            inline int &get_capacity() {return (student_capacity);};
            inline string get_name() const {return (name);};
            inline void set_name(const string n) {name = n;};
            inline string get_code() const {return (code);};
            inline void set_code(const string c) {code = c;};
            inline Student* &get_students() {return (students);};
    };
}



#endif