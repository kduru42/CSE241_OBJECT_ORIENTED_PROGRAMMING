#ifndef _ROBOCOP_H_
# define _ROBOCOP_H_

#include "humanic.h"

class robocop : public humanic
{
    private:
        string name;
        int type;
        int strength;
        int hitpoints;
        int flag;

    public:
        robocop() : humanic(), name(""), type(1), strength(30), hitpoints(40), flag(0) {}
        robocop(int new_type, int new_strength, int new_hit, string name) : humanic(new_type, new_strength, new_hit, name) {};
        ~robocop() {};
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline int get_strength() const {return (strength);};
        inline void set_strength(int s) {strength = s;};
        inline int get_hitpoints() const {return (hitpoints);};
        inline void set_hitpoints(int h) {hitpoints = h;};
        inline int get_flag() const {return (flag);};
        inline void set_flag(int f) {flag = f;};
        string get_type() const override {return ("robocop");};
        int get_damage() override
        {                   
            return (humanic::get_damage());
        }
};

#endif