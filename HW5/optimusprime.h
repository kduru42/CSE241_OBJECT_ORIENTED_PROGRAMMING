#ifndef _OPTIMUSPRIME_H_
# define _OPTIMUSPRIME_H_

#include "humanic.h"

class optimusprime : public humanic
{
    private:
        string name;
        int type;
        int strength;
        int hitpoints;
        int flag;
    
    public:
        optimusprime() : humanic(), name(""), type(0), strength(100), hitpoints(100), flag(0) {}
        optimusprime(int new_type, int new_strength, int new_hit, string name) : humanic(new_type, new_strength, new_hit, name) {};
        ~optimusprime() {};
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline int get_strength() const {return (strength);};
        inline void set_strength(int s) {strength = s;};
        inline int get_hitpoints() const {return (hitpoints);};
        inline void set_hitpoints(int h) {hitpoints = h;};
        inline int get_flag() const {return (flag);};
        inline void set_flag(int f) {flag = f;};
        string get_type() const override {return ("optimusprime");};
        int get_damage() override
        {           
            int possibility;
            possibility = rand() % 100 + 1; // %15 possibility of extra damage
            if (possibility > 0 && possibility <= 15)
                return (humanic::get_damage() * 2);
            else
                return (humanic::get_damage());
        }
};

#endif