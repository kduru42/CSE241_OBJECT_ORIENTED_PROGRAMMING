#ifndef _HUMANIC_H_
# define _HUMANIC_H_

#include "Robot.h"

class humanic : public Robot
{
    private:
        string name;
        int type;
        int strength;
        int hitpoints;
        int flag;
    
    public:
        humanic() : Robot() {flag = 0;};
        humanic(int new_type, int new_strength, int new_hit, string name) : Robot(new_type, new_strength, new_hit, name) {};
        ~humanic() {};
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
            int possibility;
            possibility = rand() % 10 + 1; // % 10 possibility to extra damage
            if (possibility == 1)
                return (Robot::get_damage() + 50);
            else
                return (Robot::get_damage());
        }
};

#endif