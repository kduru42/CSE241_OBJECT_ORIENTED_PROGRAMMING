#ifndef _BULLDOZER_H_
# define _BULLDOZER_H_
#include "Robot.h"

class bulldozer : public Robot
{
    private:
        string name;
        int type;
        int strength;
        int hitpoints;
        int flag;
    
    public:
        bulldozer() : Robot(), name(""), type(3), strength(50), hitpoints(200), flag(0) {} // constructor
        bulldozer(int new_type, int new_strength, int new_hit, string name) : Robot(new_type, new_strength, new_hit, name) {} 
        ~bulldozer() {}; // destructor
        inline string get_name() const {return (name);}; // mutators and accessers
        inline void set_name(const string n) {name = n;};
        inline int get_strength() const {return (strength);};
        inline void set_strength(int s) {strength = s;};
        inline int get_hitpoints() const {return (hitpoints);};
        inline void set_hitpoints(int h) {hitpoints = h;};
        inline int get_flag() const {return (flag);};
        inline void set_flag(int f) {flag = f;};
        string get_type() const override {return ("bulldozer");};
        int get_damage() override // the damage of bulldozer is same as Robot's default damage
        {
            return (Robot::get_damage());
        }
};


#endif