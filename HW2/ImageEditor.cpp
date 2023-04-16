#include "ImageEditor.hpp"

/*Function to read a file an store the data from the file to a vector */
void ImageEditor::read_image_data(string file_name)
{
    string img; // one coefficient of a pixel
    ifstream file; // file to read from
    file.open(file_name); // file opened
    if (file.is_open()) // checks that file is opened or not
    {
        while (file) // loop that continue until string in the file reach the end
        {
            file >> img; // reading from file
            data_saved.push_back(img); // stored data pushed to vector
        }
    }
}

/*Function to write the stored data to a new file */
void ImageEditor::write_image_data(string file_name)
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
void ImageEditor::script(float c_r, float c_g, float c_b)
{
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