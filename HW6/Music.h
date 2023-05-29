#ifndef _MUSIC_H_
# define _MUSIC_H_

#include <string>
#include <vector>
using namespace std;

class Music
{
    private:
        string title;
        string artists;
        string year;
        string genre;
    
    public:
        Music() {};
        inline string get_title() const {return (title);};
        inline string get_artists() const {return (artists);};
        inline string get_year() const {return (year);};
        inline string get_genre() const {return (genre);};
        inline void set_title(const string &t) {title = t;};
        inline void set_year(const string &y) {year = y;};
        inline void set_genre(const string &g) {genre = g;};
        inline void set_artists(const string &a) {artists = a;};
};



#endif