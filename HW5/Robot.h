#ifndef _ROBOT_H_
# define _ROBOT_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Robot
{
    private:
        int type;
        int strength;
        int hitpoints;
        string name;
        int flag;

    public:
        Robot() {flag = 0;};
        Robot(int new_type, int new_strength, int new_hit, string name) : type(new_type) ,strength(new_strength), hitpoints(new_hit), name(name) {flag = 0;};
        virtual ~Robot() {}; // virtual destructor
        virtual string get_type() const = 0;
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline int get_strength() const {return (strength);};
        inline void set_strength(int s) {strength = s;};
        inline int get_hitpoints() const {return (hitpoints);};
        inline void set_hitpoints(int h) {hitpoints = h;};
        inline int get_flag() const {return (flag);};
        inline void set_flag(int f) {flag = f;};
        virtual int get_damage();
};

#endif