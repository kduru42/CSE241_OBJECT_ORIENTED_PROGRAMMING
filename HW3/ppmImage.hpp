#ifndef _PPM_IMAGE_HPP_
# define _PPM_IMAGE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/* Class to represent image editor. */
class ppmImage
{
    private:
        vector<string> data_saved; // string vector to hold datas from input file
        int row;
        int column;
        int size; // size of data_saved

    public:
        ppmImage(); // constructor
        ppmImage(const string file_name);
        ppmImage(int x, int y);
        inline vector<string> get_data () const {return (data_saved);};
        inline void set_data(vector<string> &other) {data_saved = other;};
        inline int get_row() const {return (row);};
        inline int get_column() const {return (column);};
        inline int get_size() const {return (size);};
        inline void set_row(int x) {row = x;};
        inline void set_column(int y) {column = y;};
        inline void set_size(int s) {size = s;};
        void read_image_data(const string file_name);
        void write_image_data(const string file_name) const;
        void script(float c_r, float c_g, float c_b);
        void print_dimensions() const;
        double get_pixel(int index, const string color) const;
        void set_pixel(int index, const string color, double value);
        ppmImage operator+(const ppmImage &other) const;
        ppmImage operator-(const ppmImage &other) const;
        string &operator()(int r_index, int c_index, int channel);
        string operator()(int r_index, int c_index, int channel) const;
        friend ostream& operator<<(ostream &out, const ppmImage& obj);
};



#endif