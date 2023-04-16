#include "ppmImage.hpp"

/*Default constrcutor*/
ppmImage::ppmImage()
{
    row = 0;
    column = 0;
    size = 0;
}

/*Constrcutor with filename argument*/
ppmImage::ppmImage(const string file_name) 
{
    if (file_name.substr(file_name.size() - 3, 3) != "ppm")
        return ;
    string img; //datas from file
    ifstream file; // file variable
    file.open(file_name);
    if (file.is_open())
    {
        while (file) //while not end of file
        {
            file >> img;
            data_saved.push_back(img);
            if (data_saved.size() == 2) // saving column value
                column = img[0] - 48;
            if (data_saved.size() == 3) // saving row value
                row = img[0] - 48;
        }
    }
    size = data_saved.size();
}

/*Constructor with dimensions*/
ppmImage::ppmImage(int x, int y)
{
    if (x <= 0 || y <= 0)
        return ;
    row = x;
    column = y;
    data_saved.push_back("P3");
    data_saved.push_back(to_string(column));
    data_saved.push_back(to_string(row));
    data_saved.push_back("255");
    for (int i = 0; i < x * y * 3 + 1; i++) // pushing all 1s for white blank image
        data_saved.push_back("1");
    size = data_saved.size();
}

/*Function to read a file an store the data from the file to a vector */
void ppmImage::read_image_data(const string file_name)
{
    int count = 0;
    string img; // one coefficient of a pixel
    ifstream file; // file to read from
    file.open(file_name); // file opened
    if (file.is_open()) // checks that file is opened or not
    {
        while (file) // loop that continue until string in the file reach the end
        {
            file >> img; // reading from file
            if (count == 1)
                column = stoi(img);
            if (count == 2)
                row = stoi(img);
            if (count > 0)
                if (stoi(img) < 0 || stoi(img) > 255)
                    return ;
            data_saved.push_back(img); // stored data pushed to vector
            count++;
        }
    }
    size = data_saved.size();
    return ;
}


/*Function to write the stored data to a new file */
void ppmImage::write_image_data(const string file_name) const
{
    ofstream file; // file to write to
    file.open(file_name); // file opened
    if (file.is_open()) // checks that file is opened or not
    {
        for (int i = 0; i < data_saved.size() - 1; i++) //loop until size of data
        {
            if (i == 0 || i == 2 || i == 3 || (i - 3) % ((data_saved[1][0] - 48) * 3) == 0) // newline places
                file << data_saved[i] << "\n";
            else
                file << data_saved[i] << "\t";
        }
    }
}

/* Function to scripting pixels with input coefficients */
void ppmImage::script(float c_r, float c_g, float c_b)
{
    if (c_r < 0 || c_r >= 1 || c_g < 0 || c_g >= 1 || c_b < 0 || c_b >= 1)
        return ;
    for (int i = 4; i < data_saved.size() - 2; i+=3) // loop until data size
    {
        if ((i - 3) % 3 == 1) 
        {
            int num = (c_r * stoi(data_saved[i])) + (c_g * stoi(data_saved[i + 1])) + (c_b * stoi(data_saved[i + 2])); // result of formula
            if (num > 255) // if the num bigger than 255, remains as 255
                num = 255;
            data_saved[i] = to_string(num);
            data_saved[i + 1] = to_string(num);
            data_saved[i + 2] = to_string(num);
        }
    }
}

/*Function to print dimension counts*/
void ppmImage::print_dimensions() const
{
    cout << "Row number of the ppm image: " << row << endl;
    cout << "Column number of the ppm image: " << column << endl; 
}

/*Function to get the pixel value at the index location*/
double ppmImage::get_pixel(int index, const string color) const
{
    if (index < 0)
        return (0);
    if (color == "red")
        return (stoi(data_saved[index * 3 + 4]));
    else if (color == "green")
        return (stoi(data_saved[index * 3 + 5]));
    else if (color == "blue")
        return (stoi(data_saved[index * 3 + 6]));
    return (0);
}

/*Function to set the pixel value at the index location*/
void ppmImage::set_pixel(int index, const string color, double value)
{
    if (value < 0 || value > 255 || index < 0)
        return ;
    if (color == "red")
        data_saved[index * 3 + 4] = to_string(value);
    else if (color == "green")
        data_saved[index * 3 + 5] = to_string(value);
    else if (color == "blue")
        data_saved[index * 3 + 6] = to_string(value);
}

/*Addition operator overloading*/
ppmImage ppmImage::operator+(const ppmImage &other) const
{
    ppmImage new_obj; // new object to return
    if (data_saved.size() != other.data_saved.size())
        return (new_obj);
    new_obj.data_saved.push_back("P3");
    new_obj.data_saved.push_back(to_string(column));
    new_obj.data_saved.push_back(to_string(row));
    new_obj.data_saved.push_back("255");
    for (int i = 4; i < data_saved.size(); i++) // loop to pushing sum of the values on the objects to the new object
    {
        if (stoi(data_saved[i]) + stoi(other.data_saved[i]) > stoi(data_saved[3])) // if the value of sum bigger than 255, sets to 255
            new_obj.data_saved.push_back("255");
        else
            new_obj.data_saved.push_back(to_string((stoi(data_saved[i]) + stoi(other.data_saved[i]))));
    }
    new_obj.size = new_obj.data_saved.size();
    return (new_obj);
}

/*Subtruction operator overloading*/
ppmImage ppmImage::operator-(const ppmImage &other) const
{
    ppmImage new_obj; // new object to return 
    if (data_saved.size() != other.data_saved.size())
        return (new_obj);
    new_obj.data_saved.push_back("P3");
    new_obj.data_saved.push_back(to_string(column));
    new_obj.data_saved.push_back(to_string(row));
    new_obj.data_saved.push_back("255");
    for (int i = 4; i < data_saved.size(); i++)  // loop to pushing sum of the values on the objects to the new object
    {
        if (stoi(data_saved[i]) - stoi(other.data_saved[i]) < 0) // if subtraction less than 0, sets to 0
            new_obj.data_saved.push_back("0");
        else
            new_obj.data_saved.push_back(to_string((stoi(data_saved[i]) - stoi(other.data_saved[i]))));
    }
    new_obj.size = new_obj.data_saved.size();
    return (new_obj);
}

/*Function call operator overloading*/
string& ppmImage::operator()(int r_index, int c_index, int channel)
{
    return (data_saved[(r_index * column * 3) + (c_index * 3) + channel + 3]);
}

/* Const overload of the function call overloading */
string ppmImage::operator()(int r_index, int c_index, int channel) const
{
    return (data_saved[(r_index * column * 3) + (c_index * 3) + channel + 3]);   
}

/* Stream operator overloading */
ostream& operator<<(ostream &output, const ppmImage& obj)
{
    for (int i = 0; i < obj.data_saved.size() - 1; i++) //loop until size of data
    {
        if (i == 0 || i == 2 || i == 3 || (i - 3) % ((obj.data_saved[1][0] - 48) * 3) == 0) // newline places
            output << obj.data_saved[i] << "\n";
        else
            output << obj.data_saved[i] << "\t";
    }
    return (output);
}
