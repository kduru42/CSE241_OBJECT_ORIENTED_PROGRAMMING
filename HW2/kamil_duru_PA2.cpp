#include "ImageEditor.hpp"

int main()
{
    ImageEditor image; // image editor object
    int selection; // menu selection
    do
    {
        cout << "Main Menu\n\n"; 
        cout << "0 - Exit\n";
        cout << "1 - Open An Image(D)\n";
        cout << "2 - Save Image Data(D)\n";
        cout << "3 - Scripts(D)\n";
        do // loop to check input correctness
        {
            if (cin >> selection)
                break;
            if (cin.fail())
            {
                cin.clear(); // to clear the buffer
                cin.ignore();
            }
        } while (1);
        if (selection == 1)
        {
            int sub_selection; // sub menu selection
            string file_name; // file name
            do
            {
                cout << "OPEN AN IMAGE MENU\n";
                cout << "0 - UP\n";
                cout << "1 - Enter The Name Of The Image File\n";
                do // loop that check input correctness
                {
                    if (cin >> sub_selection)
                        break;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                } while (1);
                if (sub_selection == 1) 
                {
                    cin >> file_name;
                    image.read_image_data(file_name);
                }
            }while (sub_selection != 0);
        }
        else if (selection == 2)
        {
            int sub_selection;
            string file_name;
            do
            {
                cout << "SAVE IMAGE DATA MENU\n";
                cout << "0 - UP\n";
                cout << "1 - Enter A File Name\n";
                do
                {
                    if (cin >> sub_selection)
                        break;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                } while (1);
                if (sub_selection == 1)
                {
                    cin >> file_name;
                    image.write_image_data(file_name);
                }
            } while (sub_selection != 0);
        }
        else if (selection == 3)
        {
            int sub_selection;
            do
            {
                int sub_selection2;
                float c_r, c_g, c_b;
                cout << "SCRIPTS MENU\n";
                cout << "0 - UP\n";
                cout << "1 - Convert To Grayscale(D)\n";
                do
                {
                    if (cin >> sub_selection)
                        break;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                } while (1);
                if (sub_selection == 1)
                {
                    do
                    {
                        cout << "CONVERT TO GRAYSCALE MENU\n";
                        cout << "0 - UP\n";
                        cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
                        do
                        {
                            if (cin >> sub_selection2)
                                break;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore();
                            }
                        } while (1);
                        if (sub_selection2 == 1)
                        {
                            do
                            {
                                cin >> c_r >> c_g >> c_b;
                                if ((c_r < 0 || c_r >= 1.0) || (c_g < 0 || c_g >= 1) || (c_b < 0 || c_b >= 1))
                                    cout << "Invalid coefficient. Please try again.\n";
                            } while ((c_r < 0 || c_r >= 1.0) || (c_g < 0 || c_g >= 1) || (c_b < 0 || c_b >= 1));
                            image.script(c_r, c_g, c_b);
                        } 
                    }while (sub_selection2 != 0);
                }
            }while (sub_selection != 0);
        }
    } while (selection != 0);
}