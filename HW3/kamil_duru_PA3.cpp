#include "Test.hpp"

int main(int argc, char **argv)
{
    Test t; //object for test functions
    int choice_number = stoi(argv[1]); // number that input argument to choose operation
    string ppm_file_name1 = argv[2]; // first filename argument
    string ppm_file_name2, ppm_file_name3; // other filename arguments
    ppmImage img_obj; //ppm image object

    if (argc < 3) //argument counter should be at least 3
    {
        exit (1);
    }
    if (argv[1][0] <= '0' || argv[1][0] > '7') //checks if first argument correct
    {
        exit(1);
    }
    if (choice_number == 1) //testing addition
    {
        ppm_file_name2 = argv[3];
        ppm_file_name3 = argv[4];
        if (argc != 5)
        {
            exit(1);
        }
        t.test_addition(ppm_file_name1, ppm_file_name2, ppm_file_name3);
    }
    else if (choice_number == 2) // testing subtraction
    {
        if (argc != 5)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        ppm_file_name3 = argv[4];
        t.test_subtraction(ppm_file_name1, ppm_file_name2, ppm_file_name3);
    }
    else if (choice_number == 3) // testing swap
    {
        if (argc != 4)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        t.read_ppm(ppm_file_name1, img_obj);
        t.swap_channels(img_obj, 2);
        t.write_ppm(ppm_file_name2, img_obj);
    }
    else if (choice_number == 4)
    {
        if (argc != 4)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        t.read_ppm(ppm_file_name1, img_obj);
        t.swap_channels(img_obj, 3);
        t.write_ppm(ppm_file_name2, img_obj);
    }
    else if (choice_number == 5) // testing single color
    {
        ppmImage new_obj;
        if (argc != 4)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        t.read_ppm(ppm_file_name1, img_obj);
        new_obj = t.single_color(img_obj, 1);
        t.write_ppm(ppm_file_name2, new_obj);
    }
    else if (choice_number == 6)
    {
        ppmImage new_obj;
        if (argc != 4)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        t.read_ppm(ppm_file_name1, img_obj);
        new_obj = t.single_color(img_obj, 2);
        t.write_ppm(ppm_file_name2, new_obj);
    }
    else if (choice_number == 7)
    {
        ppmImage new_obj;
        if (argc != 4)
        {
            exit(1);
        }
        ppm_file_name2 = argv[3];
        t.read_ppm(ppm_file_name1, img_obj);
        new_obj = t.single_color(img_obj, 3);
        t.write_ppm(ppm_file_name2, new_obj);
    }

    return 0;
}