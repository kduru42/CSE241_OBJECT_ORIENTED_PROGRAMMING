#include "SchoolManagerSystem.h"
#include <limits>

int main()
{
    int selection;
    int select_student;
    int select_course;
    int select_list_student;
    SchoolManagerSystem sms;
    do
    {
        while(1)
        {
            cout << "0 exit\n" << "1 student\n" << "2 course\n" << "3 list_all_students\n" << "4 list_all_courses\n";
            cout << "<< ";
            cin >> selection;
            if (cin.fail() || (selection < 0 || selection > 4))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            if (!cin.fail() && (selection >= 0 && selection <= 4))
                break;
        }
        if (selection == 1)
        {
            do
            {
                while (1)
                {
                    cout << "0 up\n" << "1 add_student\n" << "2 select_student\n";
                    cout << "<< ";
                    cin >> select_student;
                    if (cin.fail() || (select_student < 0 || select_student > 2))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                    if (!cin.fail() && (select_student >= 0 && select_student <= 2))
                        break;
                }
                if (select_student == 1)
                {
                    string name;
                    string input;
                    unsigned int id;
                    string str_id;
                    while (1)
                    {
                        cout << "<< ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, input);
                        int index = 0;
                        while (!(input[index] >= 48 && input[index] <= 57))
                        {
                            name.push_back(input[index]);
                            index++;
                        }
                        str_id = "";
                        while (index < input.size())
                        {
                            str_id.push_back(input[index]);
                            index++;
                        }
                        if (!str_id.empty())
                            id = stoi(str_id);
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                        }
                        if (!cin.fail())
                            break;
                    }
                    sms.add_student(name, id);
                }
                else if (select_student == 2)
                {
                    string name;
                    string input;
                    unsigned int id;
                    string str_id;
                    int student_subselect;
                    int course_to_select;
                    while (1)
                    {
                        cout << "<< ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, input);
                        int index = 0;
                        while (!(input[index] >= 48 && input[index] <= 57))
                        {
                            name.push_back(input[index]);
                            index++;
                        }
                        str_id = "";
                        while (index < input.size())
                        {
                            str_id.push_back(input[index]);
                            index++;
                        }
                        if (!str_id.empty())
                            id = stoi(str_id);
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                        }
                        if (!cin.fail())
                            break;
                    }
                    do
                    {
                        while (1)
                        {
                            cout << "0 up\n" << "1 delete_student\n" << "3 add_selected_student_to_a_course\n" << "4 drop_selected_student_from_a_course\n";
                            cout << ">> ";
                            cin >> student_subselect;
                            if (cin.fail() || (student_subselect < 0 || student_subselect > 4 || student_subselect == 2))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                            }
                            if (!cin.fail() && (student_subselect >= 0 && student_subselect <= 4 && student_subselect != 2))
                                break;
                        }
                        if (student_subselect == 1)
                        {
                            sms.delete_student(name, id);
                            break;
                        }
                        else if (student_subselect == 3)
                        {
                            sms.decide_courses_not_taken(name, id);
                            while (1)
                            {
                                cout << "<< ";
                                cin >> course_to_select;
                                if (course_to_select == 0)
                                    break;
                                if (cin.fail() || (course_to_select < 0))
                                {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                                if (!cin.fail() && (select_student >= 0))
                                    break;
                            }
                            if (course_to_select == 0)
                                break;
                            sms.add_selected_student_to_a_course(name, id, course_to_select);
                        }
                        else if (student_subselect == 4)
                        {
                            sms.list_cources_that_is_taken(name, id);
                            while (1)
                             {
                                 cout << "<< ";
                                 cin >> course_to_select;
                                 if (course_to_select == 0)
                                     break;
                                 if (cin.fail() || (course_to_select < 0))
                                 {
                                     cin.clear();
                                     cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                 }
                                 if (!cin.fail() && (select_student >= 0))
                                     break;
                             }
                             if (course_to_select == 0)
                                 break;
                             sms.drop_selected_student_from_a_course(name, id, course_to_select);
                        }
                    }while(student_subselect);
                }
            }while(select_student);
        }
        else if (selection == 2)
        {
            do
            {
                while (1)
                {
                    cout << "0 up\n" << "1 add_course\n" << "2 select_course\n";
                    cout << "<< ";
                    cin >> select_course;
                    if (cin.fail() || (select_course < 0 || select_course > 2))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                    if (!cin.fail() && (select_course >= 0 && select_course <= 2))
                        break;
                }
                if (select_course == 1)
                {
                    string name;
                    string input;
                    string code;
                    while (1)
                    {
                        cout << "<< ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, input);
                        int index = 0;
                        while (input[index] != ' ')
                        {
                            code.push_back(input[index]);
                            index++;
                        }
                        while (index < input.size())
                        {
                            name.push_back(input[index]);
                            index++;
                        }
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                        }
                        if (!cin.fail())
                            break;
                    }
                    sms.add_course(code, name);
                }
                else if (select_course == 2)
                {
                    string name;
                    string input;
                    string code;
                    int course_subselect;
                    while (1)
                    {
                        cout << "<< ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, input);
                        int index = 0;
                        while (input[index] != ' ')
                        {
                            code.push_back(input[index]);
                            index++;
                        }
                        while (index < input.size())
                        {
                            name.push_back(input[index]);
                            index++;
                        }
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                        }
                        if (!cin.fail())
                            break;
                    }
                    do
                    {
                        while (1)
                        {
                            cout << "0 up\n" << "1 delete_course\n" << "2 list_students_registered_to_the_selected_course\n";
                            cout << ">> ";
                            cin >> course_subselect;
                            if (cin.fail() || (course_subselect < 0 || course_subselect > 2))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');    
                            }
                            if (!cin.fail() && (course_subselect >= 0 && course_subselect <= 2))
                                break;
                        }
                        if (course_subselect == 1)
                        {
                            sms.delete_course(code, name);
                            break;
                        }
                        else if (course_subselect == 2)
                            sms.list_students_registered_to_the_selected_course(code, name);
                    }while(course_subselect);
                }
            }while(select_course);
        }
        else if (selection == 3)
            sms.list_all_students();
        else if (selection == 4)
            sms.list_all_courses();

    }while(selection);
    return (0);
}
