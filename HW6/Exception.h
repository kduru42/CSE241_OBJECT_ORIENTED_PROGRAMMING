#ifndef _EXCEPTION_H_
# define _EXCEPTION_H_

#include <string>
#include <exception>
using namespace std;

class MissingFieldException : public exception
{
    private:
        string message;
    
    public:
        MissingFieldException(const string &m) {message = m;};
        inline string get_message() const {return (message);};    
        /* function to provide a descriptive error message associated with the exception */
        const char* what() const noexcept override {return (message.c_str());}; 
};

class DublicateEntryException : public exception
{
    private:
        string message;
    
    public:
        DublicateEntryException(const string &m) {message = m;};
        inline string get_message() const {return (message);};
        const char* what() const noexcept override {return (message.c_str());};
};

class WrongCommandException : public exception
{
    private:
        string message;
    
    public:
        WrongCommandException(const string &m) {message = m;};
        inline string get_message() const {return (message);};
        const char* what() const noexcept override {return (message.c_str());};
};

#endif