#ifndef _APPLICATION_H_
# define _APPLICATION_H_

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "Music.h"
#include "Movie.h"
#include "File.h"
#include "Exception.h"

template <typename T>
class Application
{
    friend class File;
    private:
        vector<T> catalog; // data vector
        string type; // data type
        static string which; // variable to use in comparator function
        ofstream output_file; // output.txt file variable
        int size; // data size

    public:
        Application() {size = 0;};
        Application(string t);
        ~Application();
        inline vector<T> get_catalog() const {return (catalog);};
        inline void set_catalog(const T &data) {catalog.push_back(data); size++;};
        inline int get_size() const {return (size);};
        void read_datas();
        void read_commands();
        void command_search(const string &to_find, const string &where);
        void command_sort(const string &which);
        void print_infos(const T &t);
        bool check_dublicate(const T &t) const;
        bool check_fields(const string & field) const;
        static bool comparator(const T &t1, const T &t2);
};

template<typename T>
string Application<T>::which;

template <>
bool Application<Movie>::comparator(const Movie& m1, const Movie& m2);
template <>
bool Application<Book>::comparator(const Book& b1, const Book& b2);
template <>
bool Application<Music>::comparator(const Music& m1, const Music& m2);
template <>
void Application<Movie>::print_infos(const Movie& m);
template <>
void Application<Book>::print_infos(const Book& m);
template <>
void Application<Music>::print_infos(const Music& m);

/* Function to check if the field name in the command for movie object is wrong */
template<>
bool Application<Movie>::check_fields(const string &field) const
{
    if (field != "title" && field != "director" && field != "year" 
            && field != "genre" && field != "starrings")
            return (false);
    return (true);
}

/* Function to check if the field name in the command for book object is wrong */
template<>
bool Application<Book>::check_fields(const string &field) const
{
    if (field != "title" && field != "authors" && field != "year" 
            && field != "tags")
            return (false);
    return (true);
}

/* Function to check if the field name in the command for music object is wrong */
template<>
bool Application<Music>::check_fields(const string &field) const
{
    if (field != "title" && field != "artists" && field != "year" 
            && field != "genre")
            return (false);
    return (true);
}

/* Constructor */
template <typename T>
Application<T>::Application(string t)
{
    type = t;
    size = 0;
    output_file.open("output.txt", ios::app);
}

/* Destructor */
template <typename T>
Application<T>::~Application()
{
    output_file.close();
}

/* Function to read datas in the datas.txt for movie object */
template <>
void Application<Movie>::read_datas()
{
    ifstream my_file("data.txt", ios::in); // input file
    string line; // variable to keep each line

    output_file << "Catalog Read: " << type << endl;
    if (my_file.is_open())
    {
        while(getline(my_file, line))
        {
            Movie obj;
            // read the line of data into a string stream for tokenization
            istringstream iss(line);
            string token;

            if (count(line.begin(), line.end(), '"') == 0) // if the first line, continues
                continue;

            int num_quotes = count(line.begin(), line.end(), '"'); // storing the quote count to check field count


            getline(iss, token, '"'); // read until the first double quote
            getline(iss, token, '"'); // read the movie title
            obj.set_title(token);

            getline(iss, token, '"'); // read until the second double quote
            getline(iss, token, '"'); // read the director
            obj.set_director(token);

            getline(iss, token, '"'); // read until the third double quote
            getline(iss, token, '"'); // read the year
            obj.set_year(token);

            getline(iss, token, '"'); // read until the fourth double quote
            getline(iss, token, '"'); // read the tags
            obj.set_genre(token);

            getline(iss, token, '"'); // read until the fourth double quote
            getline(iss, token, '"'); // read the tags
            obj.set_starrings(token);

            try
            {
                if (num_quotes != 10) // if there is no quote enough, throws exception
                    throw MissingFieldException("Exception: missing field");
                else if (check_dublicate(obj) == false) // if there is dublicate, throws exception
                    throw DublicateEntryException("Exception: dublicate entry");
                else
                    set_catalog(obj); // if there is no problem, pushes to catalog
            }
            catch(MissingFieldException &mfe)
            {
                output_file << mfe.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
            catch(DublicateEntryException &dee)
            {
                output_file << dee.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
        }
        output_file << size << " unique entries" << endl;
        my_file.close();
    }
}

/* Function to read datas in the datas.txt for book object */
template <>
void Application<Book>::read_datas()
{
    ifstream my_file("data.txt", ios::in);
    string line;

    output_file << "Catalog Read: " << type << endl;
    if (my_file.is_open())
    {
        while(getline(my_file, line))
        {
            Book obj;
            // read the line of data into a string stream for tokenization
            istringstream iss(line);
            string token;

            if (count(line.begin(), line.end(), '"') == 0)
                continue;

            int num_quotes = count(line.begin(), line.end(), '"');


            getline(iss, token, '"'); // read until the first double quote
            getline(iss, token, '"'); // read the movie title
            obj.set_title(token);

            getline(iss, token, '"'); // read until the second double quote
            getline(iss, token, '"'); // read the director
            obj.set_authors(token);

            getline(iss, token, '"'); // read until the third double quote
            getline(iss, token, '"'); // read the year
            obj.set_year(token);

            getline(iss, token, '"'); // read until the fourth double quote
            getline(iss, token, '"'); // read the tags
            obj.set_tags(token);

            try
            {
                if (num_quotes != 8)
                    throw MissingFieldException("Exception: missing field");
                else if (check_dublicate(obj) == false)
                    throw DublicateEntryException("Exception: dublicate entry");
                else
                    set_catalog(obj);
            }
            catch(MissingFieldException &mfe)
            {
                output_file << mfe.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
            catch(DublicateEntryException &dee)
            {
                output_file << dee.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
        }
        output_file << size << " unique entries" << endl;
        my_file.close();
    }
}

/* Function to read datas in the datas.txt for music object */
template <>
void Application<Music>::read_datas()
{
    ifstream my_file("data.txt", ios::in);
    string line;

    output_file << "Catalog Read: " << type << endl;
    if (my_file.is_open())
    {
        while(getline(my_file, line))
        {
            Music obj;
            // read the line of data into a string stream for tokenization
            istringstream iss(line);
            string token;

            if (count(line.begin(), line.end(), '"') == 0)
                continue;

            int num_quotes = count(line.begin(), line.end(), '"');


            getline(iss, token, '"'); // read until the first double quote
            getline(iss, token, '"'); // read the movie title
            obj.set_title(token);

            getline(iss, token, '"'); // read until the second double quote
            getline(iss, token, '"'); // read the director
            obj.set_artists(token);

            getline(iss, token, '"'); // read until the third double quote
            getline(iss, token, '"'); // read the year
            obj.set_year(token);

            getline(iss, token, '"'); // read until the fourth double quote
            getline(iss, token, '"'); // read the tags
            obj.set_genre(token);

            try
            {
                if (num_quotes != 8)
                    throw MissingFieldException("Exception: missing field");
                else if (check_dublicate(obj) == false)
                    throw DublicateEntryException("Exception: dublicate entry");
                else
                    set_catalog(obj);
            }
            catch(MissingFieldException &mfe)
            {
                output_file << mfe.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
            catch(DublicateEntryException &dee)
            {
                output_file << dee.get_message() << endl;
                print_infos(obj);
                output_file << endl;
            }
        }
        output_file << size << " unique entries" << endl;
        my_file.close();
    }
}

/* Function to read commands and execute them */
template <typename T>
void Application<T>::read_commands()
{
    ifstream my_file("commands.txt", ios::in); // commands file variable
    string line; // variable to store each line

    if (my_file.is_open())
    {
        while (getline(my_file, line))
        {
            istringstream iss(line);
            string token1;
            string token2;

            try // if there is a word except the commands, throws exception
            {
                if (line.substr(0, 6) != "search" && line.substr(0, 4) != "sort")
                    throw WrongCommandException("Exception: wrong command");
            }
            catch (WrongCommandException &wce)
            {
                output_file << wce.get_message() << endl;
                output_file << line << endl;
            }

            if (line.substr(0, 6) == "search")
            {
                getline(iss, token1, '"');
                getline(iss, token1, '"');
                getline(iss, token2, '"');
                getline(iss, token2, '"');
                try // if the field that will be searched is not valid, throws exception
                {
                    if (token1 == "" || !check_fields(token2))
                        throw WrongCommandException("Exception: wrong command");
                    else
                    {
                        output_file << line << endl;
                        command_search(token1, token2);
                    }
                }
                catch (WrongCommandException &wce)
                {
                    output_file << wce.get_message() << endl;
                    output_file << line << endl;
                }
            }
            else if (line.substr(0, 4) == "sort")
            {
                getline(iss, token1, '"');
                getline(iss, token1, '"');
                try // if the field that will be sorted is not valid, throws exceptions
                {
                    if (!check_fields(token1))
                        throw WrongCommandException("Exception: wrong command");
                    else
                    {
                        output_file << line << endl;
                        command_sort(token1);
                    }
                }
                catch (WrongCommandException &wce)
                {
                    output_file << wce.get_message() << endl;
                    output_file << line << endl;
                }
            }
        }
        my_file.close();
    }
}

/* Function to execute the process of search command for movie object*/
template <>
void Application<Movie>::command_search(const string &to_find, const string &where)
{
    int found; // variable to check if find function returns the valid string

    if (where == "title")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_title().find(to_find);
            if (found != string::npos) // if the searched string found in title, prints the infos of the object
                print_infos(catalog[i]);
        }
    }
    else if (where == "director")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_director().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]); 
        }
    }
    else if (where == "year")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_year().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]); 
        }
    }
    else if (where == "genre")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_genre().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);  
        }
    }
    else if (where == "starrings")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_starrings().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);  
        }
    }
    output_file << endl;
}

/* Function to execute the process of search command for book object*/
template<>
void Application<Book>::command_search(const string &to_find, const string &where)
{
    int found;

    if (where == "title")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_title().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]); 
        }
    }
    else if (where == "authors")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_authors().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);  
        }
    }
    else if (where == "year")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_year().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]); 
        }
    }
    else if (where == "tags")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_tags().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);   
        }
    }
    output_file << endl;
}

/* Function to execute the process of search command for music object*/
template<>
void Application<Music>::command_search(const string &to_find, const string &where)
{
    int found;

    if (where == "title")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_title().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);
        }
    }
    else if (where == "artists")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_artists().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);
        }
    }
    else if (where == "year")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_year().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);  
        }
    }
    else if (where == "genre")
    {
        for (int i = 0; i < size; i++)
        {
            found = catalog[i].get_genre().find(to_find);
            if (found != string::npos)
                print_infos(catalog[i]);
        }
    }
    output_file << endl;
}

/* Function to execute the process of sort command for movie object */
template <>
void Application<Movie>::command_sort(const string &which)
{
    this->which = which; // which field accorting to be sorted
    sort(catalog.begin(), catalog.end(), comparator); // sort function with comparator function
    for (int i = 0; i < size; i++) // printing sorted datas
    {
        print_infos(catalog[i]);
        output_file << endl;
    }
}

/* Function to execute the process of sort command for book object */
template<> 
void Application<Book>::command_sort(const string &which)
{
    this->which = which;
    sort(catalog.begin(), catalog.end(), comparator);
    for (int i = 0; i < size; i++)
    {
        print_infos(catalog[i]);
        output_file << endl;
    }
}

/* Function to execute the process of sort command for music object */
template<>
void Application<Music>::command_sort(const string &which)
{
    this->which = which;
    sort(catalog.begin(), catalog.end(), comparator);
    for (int i = 0; i < size; i++)
    {
        print_infos(catalog[i]);
        output_file << endl;
    }
}

/* Comparator function for movie objects to pass to sort function as an argument */
template<>
bool Application<Movie>::comparator(const Movie &m1, const Movie &m2)
{
    if (which == "title")
        return (m1.get_title() < m2.get_title());
    else if (which == "director")
        return (m1.get_director() < m2.get_director());
    else if (which == "year")
        return (m1.get_year() < m2.get_year());
    else if (which == "genre")
        return (m1.get_genre() < m2.get_genre());
    else
        return (m1.get_starrings() < m2.get_starrings());
}

/* Comparator function for book objects to pass to sort function as an argument */
template<>
bool Application<Book>::comparator(const Book &b1, const Book &b2)
{
    if (which == "title")
        return (b1.get_title() < b2.get_title());
    else if (which == "year")
        return (b1.get_year() < b2.get_year());
    else if (which == "authors")
        return (b1.get_authors() < b2.get_authors());
    else
        return (b1.get_tags() < b2.get_tags());
}

/* Comparator function for music objects to pass to sort function as an argument */
template<>
bool Application<Music>::comparator(const Music &m1, const Music &m2)
{
    if (which == "title")
        return (m1.get_title() < m2.get_title());
    else if (which == "year")
        return (m1.get_year() < m2.get_year());
    else if (which == "genre")
        return (m1.get_genre() < m2.get_genre());
    else
        return (m1.get_artists() < m2.get_artists());
}

/* Function to print infos for movie object */
template<>
void Application<Movie>::print_infos(const Movie &t)
{
    if (t.get_title() != "")
        output_file << "\"" << t.get_title() << "\" ";
    if (t.get_director() != "")
        output_file << "\"" << t.get_director() << "\" ";
    if (t.get_year() != "")
        output_file << "\"" << t.get_year() << "\" ";
    if (t.get_genre() != "")
        output_file << "\"" << t.get_genre() << "\" ";
    if (t.get_starrings() != "")
        output_file << "\"" << t.get_starrings() << "\"";
}

/* Function to print infos for book object */
template<>
void Application<Book>::print_infos(const Book &t)
{
    if (t.get_title() != "")
        output_file << "\"" << t.get_title() << "\" ";
    if (t.get_authors() != "")
        output_file << "\"" << t.get_authors() << "\" ";
    if (t.get_year() != "")
        output_file << "\"" << t.get_year() << "\" ";
    if (t.get_tags() != "")
        output_file << "\"" << t.get_tags() << "\"";
}

/* Function to print infos for music object */
template<>
void Application<Music>::print_infos(const Music &t)
{
    if (t.get_title() != "")
        output_file << "\"" << t.get_title() << "\" ";
    if (t.get_artists() != "")
        output_file << "\"" << t.get_artists() << "\" ";
    if (t.get_year() != "")
        output_file << "\"" << t.get_year() << "\" ";
    if (t.get_genre() != "")
        output_file << "\"" << t.get_genre() << "\"";
}

/* Funciton to check dublicates if there is any in data file */
template<typename T>
bool Application<T>::check_dublicate(const T &t) const
{
    for (int i = 0; i < size; i++)
    {
        if (t.get_title() == catalog[i].get_title())
            return (false);
    }
    return (true);
}

#endif