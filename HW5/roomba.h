#ifndef _ROOMBA_H_
# define _ROOMBA_H_
#include "Robot.h"

class roomba : public Robot
{
    private:
        string name;
        int type;
        int strength;
        int hitpoints;
        int flag;
    
    public:
        roomba() : Robot(), name(""), type(2), strength(3), hitpoints(10), flag(0) {}
        roomba(int new_type, int new_strength, int new_hit, string name) : Robot(new_type, new_strength, new_hit, name) {};
        ~roomba() {};
        inline string get_name() const {return (name);};
        inline void set_name(const string n) {name = n;};
        inline int get_strength() const {return (strength);};
        inline void set_strength(int s) {strength = s;};
        inline int get_hitpoints() const {return (hitpoints);};
        inline void set_hitpoints(int h) {hitpoints = h;};
        inline int get_flag() const {return (flag);};
        inline void set_flag(int f) {flag = f;};
        string get_type() const override {return ("roomba");};
        int get_damage() override
        {
            return (Robot::get_damage() * 2);
        }
};


#endif