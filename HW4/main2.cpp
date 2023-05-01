#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string name;
    string input;
    unsigned int id;
    string str_id;
    while (1)
    {
        cout << "<< ";
        getline(cin, input);
        int index = 0;
        while (!(input[index] >= 48 && input[index] <= 57))
        {
            name.push_back(input[index]);
            index++;
        }
        while (index < input.size())
        {
            str_id.push_back(input[index]);
            index++;
        }
        id = stoi(str_id);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');    
        }
        if (!cin.fail())
            break;

    }
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    return 0;
}
