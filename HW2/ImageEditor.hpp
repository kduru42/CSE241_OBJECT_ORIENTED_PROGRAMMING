#ifndef _PA2_HPP_
# define _PA2_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/* Class to represent image editor. */
class ImageEditor 
{
    private:
        vector<string> data_saved; // string vector to hold datas from input file
        fstream saved_image; // variable to hold saved file

    public:
        ImageEditor() {}; // constructor
        void read_image_data(string file_name);
        void write_image_data(string file_name);
        void script(float c_r, float c_g, float c_b);

};

#endif