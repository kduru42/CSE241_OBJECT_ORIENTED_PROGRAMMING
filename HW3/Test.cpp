#include "Test.hpp"

/*Test function to test read_image_data*/
int Test::read_ppm(const string source_ppm_file_name, ppmImage& destination_object)
{
    destination_object.read_image_data(source_ppm_file_name);
    if (destination_object.get_size() == 0) // if not successfull returns 0
        return (0);
    return (1);
}

/*Test function to test write_image_data*/
int Test::write_ppm(const string destination_ppm_file_name, const ppmImage& source_object)
{
    if (source_object.get_size() == 0) // if not successfull returns 0
        return (0);
    source_object.write_image_data(destination_ppm_file_name);
    return (1);
}

/*Test function to test addition overloading*/
int Test::test_addition(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage obj1(filename_image1); // first object to sum
    ppmImage obj2(filename_image2); // second object to sum
    ppmImage obj3; // returning object of sum
    obj3 = obj1 + obj2;
    if (obj3.get_size() != obj1.get_size()) // if addition not succesfull, return 0
        return (0);
    write_ppm(filename_image3, obj3); // writes data to a new file
    return (1);
}
/*Test function to test subtraction overloading*/
int Test::test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)
{
    ppmImage obj1(filename_image1); //first object to subtract
    ppmImage obj2(filename_image2); //second object to subtract
    ppmImage obj3; // returning object of subtraction
    obj3 = obj1 - obj2;
    if (obj3.get_size() != obj1.get_size()) // if subtraction not successfull, returns 0
        return (0);
    write_ppm(filename_image3, obj3); // writes data to a new file
    return (1);
}

/*Test function to test stream overload*/
int Test::test_print(const string filename_image1)
{
    ppmImage obj(filename_image1);
    if (obj.get_size() == 0)
        return (0);
    cout << obj;
    return (1);
}

/*Function to swap channels with function call operator*/
int Test::swap_channels(ppmImage& image_object_to_be_modified, int swap_choice)
{
    if (image_object_to_be_modified.get_size() == 0)
        return (0);
    string temp;
    if (swap_choice == 1) // if swap choice is 1, swaps red and green
    {
        for (int i = 0; i < image_object_to_be_modified.get_row(); i++) // nested loop to change all channels in the file
        {
            for (int j = 0; j < image_object_to_be_modified.get_column(); j++)
            {
                temp = image_object_to_be_modified(i, j, 1);
                image_object_to_be_modified(i, j, 1) = image_object_to_be_modified(i, j, 2);
                image_object_to_be_modified(i, j, 2) = temp;
            }
        }
    }
    else if (swap_choice == 2) // if swap choice is 2, swaps red and blue
    {
        for (int i = 0; i < image_object_to_be_modified.get_row(); i++)
        {
            for (int j = 0; j < image_object_to_be_modified.get_column(); j++)
            {
                temp = image_object_to_be_modified(i, j, 1);
                image_object_to_be_modified(i, j, 1) = image_object_to_be_modified(i, j, 3);
                image_object_to_be_modified(i, j, 3) = temp;
            }
        }
    }
    else if (swap_choice == 3) // if swap choice is 3, swaps green and blue
    {
        for (int i = 0; i < image_object_to_be_modified.get_row(); i++)
        {
            for (int j = 0; j < image_object_to_be_modified.get_column(); j++)
            {
                temp = image_object_to_be_modified(i, j, 2);
                image_object_to_be_modified(i, j, 2) = image_object_to_be_modified(i, j, 3);
                image_object_to_be_modified(i, j, 3) = temp;
            }
        }
    }
    return (1);
}

/*Function to sets pixel of just one channel with the source data and sets other channels to 0*/
ppmImage Test::single_color(const ppmImage& source, int color_choice)
{
    ppmImage new_obj(source.get_row(), source.get_column());
    if (color_choice == 1) // if color choice is 1, sets red channel
    {
        for (int i = 0; i < source.get_row(); i++) // nester loop to set all pixels of file
        {
            for (int j = 0; j < source.get_column(); j++)
            {
                new_obj(i, j, 1) = source(i, j, 1);
                new_obj(i, j, 2) = "0";
                new_obj(i, j, 3) = "0";
            }
        }
    }
    else if (color_choice == 2) // if color choice is 2, sets green channel
    {
        for (int i = 0; i < source.get_row(); i++)
        {
            for (int j = 0; j < source.get_column(); j++)
            {
                new_obj(i, j, 1) = "0";
                new_obj(i, j, 2) = source(i, j, 2);
                new_obj(i, j, 3) = "0";
            }
        }
    }
    else if (color_choice == 3) // if color choice is 3, sets blue channel
    {
        for (int i = 0; i < source.get_row(); i++)
        {
            for (int j = 0; j < source.get_column(); j++)
            {
                new_obj(i, j, 1) = "0";
                new_obj(i, j, 2) = "0";
                new_obj(i, j, 3) = source(i, j, 3);
            }
        }
    }
    return (new_obj);
}