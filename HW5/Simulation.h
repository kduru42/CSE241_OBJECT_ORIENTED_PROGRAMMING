#ifndef _SIMULATION_H_
# define _SIMULATION_H_

#include "bulldozer.h"
#include "optimusprime.h"
#include "robocop.h"
#include "roomba.h"
#include <vector>
#include <algorithm>



class Simulation
{
    friend class Robot;

    private:
        int grid_size;
        int robot_count;
        Robot *grid[10][10];

    public:
        Simulation();
        ~Simulation();
        inline int get_grid_size() const {return (grid_size);};
        inline int get_robot_count() const {return (robot_count);};
        void put_robots_to_grid();
        void turn();
        void simulation_loop();
        void display();
        void move_until_fight(Robot *r, int i, int j, int dir);
        void set_flag_to_zero();
        int fight_loop(Robot *r, Robot *s);
};

#endif