#ifndef _BOOK_H_
# define _BOOK_H_

#include <string>
#include <vector>
using namespace std;

class Book
{
    private:
        string title;
        string authors;
        string year;
        string tags;
    
    public:
        Book() {};
        inline string get_title() const {return (title);};
        inline string get_authors() const {return (authors);};
        inline string get_year() const {return (year);};
        inline string get_tags() const {return (tags);};
        inline void set_title(const string &t) {title = t;};
        inline void set_year(const string &y) {year = y;};
        inline void set_authors(const string &a) {authors = a;};
        inline void set_tags(const string &t) {tags = t;};
};



#endif