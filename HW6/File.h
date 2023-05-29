#ifndef _FILE_H_
# define _FILE_H_

#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class File
{
    private:
        string type;

    public:
        File() {};
        inline string get_type() const {return (type);};
        string read_type();
};

#endif