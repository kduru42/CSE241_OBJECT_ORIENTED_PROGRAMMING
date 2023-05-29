#include "File.h"

/* Function to detect data type from data.txt */
string File::read_type()
{
    ifstream my_file;
    string type;
    my_file.open("data.txt");
    if (my_file.is_open())
        my_file >> type;

    my_file.close();
    
    return (type);
}

   