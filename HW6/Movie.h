#ifndef _MOVIE_H_
# define _MOVIE_H_

#include <string>
#include <vector>
using namespace std;

class Movie
{
    private:
        string title;
        string director;
        string year;
        string genre;
        string starrings;
    
    public:
        Movie() {};
        inline string get_title() const {return (title);};
        inline string get_director() const {return (director);};
        inline string get_year() const {return (year);};
        inline string get_genre() const {return (genre);};
        inline string get_starrings() const {return (starrings);};
        inline void set_title(const string &t) {title = t;};
        inline void set_director(const string &d){director = d;};
        inline void set_year(const string &y) {year = y;};
        inline void set_genre(const string &g) {genre = g;};
        inline void set_starrings(const string &s) {starrings = s;};
};



#endif