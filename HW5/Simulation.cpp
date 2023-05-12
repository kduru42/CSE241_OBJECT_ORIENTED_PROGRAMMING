#include "Simulation.h"

/* Constructor */
Simulation::Simulation()
{
    srand((unsigned int)time(NULL)); // to randomize return of value of rand()
    grid_size = 10;
    robot_count = 0;
    for (int i = 0; i < grid_size; i++) // initializing the grid
        for (int j = 0; j < grid_size; j++)
            grid[i][j] = NULL;
}

/* Destructor */
Simulation::~Simulation()
{
    for (int i = 0; i < grid_size; i++)
        for (int j = 0; j < grid_size; j++)
            if (grid[i][j] != NULL) // deleting the location if there is an object
                delete grid[i][j];
}

/* Function to put robots to a random location in the grid */
void Simulation::put_robots_to_grid()
{
    int pos1, pos2;
    vector<pair<int, int>> empty_positions; // pair to store locations
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            empty_positions.push_back(make_pair(i, j));
    random_shuffle(empty_positions.begin(), empty_positions.end()); // shuffling pair to randomize locations
    
    int i = 0;
    while (i < 5)
    {
        string name = "bulldozer_" + to_string(i);
        bulldozer *obj = new bulldozer(3, 50, 200, name);
        pair <int, int> position = empty_positions.back(); // taking a random position from pair
        empty_positions.pop_back(); // popping the last position value from pair
        pos1 = position.first;
        pos2 = position.second;
        if (grid[pos1][pos2] == NULL) // if the position is emtpy, putting the robot into the position
        {
            grid[pos1][pos2] = obj;
            robot_count++;
            i++;
        }
    }

    // same operations for other robots
    i = 0;
    while (i < 5)
    {
        string name = "optimusprime_" + to_string(i);
        optimusprime *obj = new optimusprime(0, 100, 100, name);
        pair <int, int> position = empty_positions.back();
        empty_positions.pop_back();
        pos1 = position.first;
        pos2 = position.second;
        if (grid[pos1][pos2] == NULL)
        {
            grid[pos1][pos2] = obj;
            robot_count++;
            i++;
        }
    }

    i = 0;
    while (i < 5)
    {
        string name = "robocop_" + to_string(i);
        robocop *obj = new robocop(1, 30, 40, name);
        pair <int, int> position = empty_positions.back();
        empty_positions.pop_back();
        pos1 = position.first;
        pos2 = position.second;
        if (grid[pos1][pos2] == NULL)
        {
            grid[pos1][pos2] = obj;
            robot_count++;
            i++;
        }
    }

    i = 0;
    while (i < 5)
    {
        string name = "roomba_" + to_string(i);
        roomba *obj = new roomba(2, 3, 10, name);
        pair <int, int> position = empty_positions.back();
        empty_positions.pop_back();
        pos1 = position.first;
        pos2 = position.second;
        if (grid[pos1][pos2] == NULL)
        {
            grid[pos1][pos2] = obj;
            robot_count++;
            i++;
        }
    }
}

/* Function to simulate one turn */
void Simulation::turn()
{
    int to_move;
    int f = 0;
    set_flag_to_zero(); // setting the flags of all robots to zero before turn starts
    for (int i = 0; i < grid_size; i++)
    {
        for (int j = 0; j < grid_size; j++)
        {
            if (grid[i][j] != NULL) // if there is robot in the location
            {
                f = grid[i][j]->get_flag();
                while(f != 1) // while robot is not set to moved
                {
                    to_move = rand() % 4 + 1; // where to locate
                    if (to_move == 1 && i != 0) // up
                    {
                        if (grid[i - 1][j] != NULL) // if there is a robot in the target location, fights with the robot
                        {
                            int which_died;
                            which_died = fight_loop(grid[i][j], grid[i - 1][j]);
                            if (which_died == 0)
                            {
                                delete grid[i - 1][j];
                                grid[i - 1][j] = NULL;
                                grid[i][j]->set_flag(1);
                            }
                            else if (which_died == 1)
                            {
                                delete grid[i][j];
                                grid[i][j] = NULL;
                                grid[i - 1][j]->set_flag(1);
                            }  
                        }
                        else // else moves until finds another robot
                            move_until_fight(grid[i][j], i, j, to_move);
                        robot_count--;
                        f = 1;
                    }
                    else if (to_move == 2 && j != grid_size - 1) // right
                    {
                        if (grid[i][j + 1] != NULL)
                        {
                            int which_died;
                            which_died = fight_loop(grid[i][j], grid[i][j + 1]);
                            if (which_died == 0)
                            {
                                delete grid[i][j + 1];
                                grid[i][j + 1] = NULL;
                                grid[i][j]->set_flag(1);
                            }
                            else if(which_died == 1)
                            {
                                delete grid[i][j];
                                grid[i][j] = NULL;
                                grid[i][j + 1]->set_flag(1);
                            }
                        }
                        else
                            move_until_fight(grid[i][j], i, j, to_move);
                        robot_count--;
                        f = 1;
                    }
                    else if (to_move == 3 && i != grid_size - 1) // down
                    {
                        if (grid[i + 1][j] != NULL)
                        {
                            int which_died;
                            which_died = fight_loop(grid[i][j], grid[i + 1][j]);
                            if (which_died == 0)
                            {
                                delete grid[i + 1][j];
                                grid[i + 1][j] = NULL;
                                grid[i][j]->set_flag(1);
                            }
                            else if(which_died == 1)
                            {
                                delete grid[i][j];
                                grid[i][j] = NULL;
                                grid[i + 1][j]->set_flag(1);
                            }
                        }
                        else
                            move_until_fight(grid[i][j], i, j, to_move);
                        robot_count--;
                        f = 1;
                    }
                    else if (to_move == 4 && j != 0) // left
                    {
                        if (grid[i][j - 1] != NULL)
                        {
                            int which_died;
                            which_died = fight_loop(grid[i][j], grid[i][j - 1]);
                            if (which_died == 0)
                            {
                                delete grid[i][j - 1];
                                grid[i][j - 1] = NULL;
                                grid[i][j]->set_flag(1);
                            }
                            else if (which_died == 1)
                            {
                                delete grid[i][j];
                                grid[i][j] = NULL;
                                grid[i][j - 1]->set_flag(1);
                            }
                        }
                        else
                            move_until_fight(grid[i][j], i, j, to_move);
                        robot_count--;
                        f = 1;
                    }
                }
            }
        }
    }
}

/* Function to make two robots fight with each other until one of the robots dies */
int Simulation::fight_loop(Robot *r, Robot *s)
{
    if (!r || !s)
        return(-1);
    int d_r; // variable to store damage of one robot
    int r_point = r->get_hitpoints();
    int s_point = s->get_hitpoints();
    while (1)
    {
        d_r = r->get_damage();
        cout << r->get_name() << "(" << r_point << ")" << " hits " 
                << s->get_name() << "(" << s_point << ")" << " with " << d_r << endl; 
        s->set_hitpoints(s_point - d_r); // increasing the hitpoint of the target robot by damage of attacker robot
        s_point -= d_r;
        if(s->get_hitpoints() <= 0) // if the target dies, prints the death massage and returns
        {
            cout << s->get_name() << " has been died.\n" << endl;
            return (0);
        }
        d_r = s->get_damage();
        cout << s->get_name() << "(" << s_point << ")" << " hits " 
                << r->get_name() << "(" << r_point << ")" << " with " << d_r << endl;
        r->set_hitpoints(r_point - d_r);
        r_point -= d_r;
        if (r->get_hitpoints() <= 0)
        {
            cout << r->get_name() << " has been died.\n" << endl;
            return (1);
        }
    }
    return (0);
}

/* Function to loop simulation until there is one robot left alive */
void Simulation::simulation_loop()
{
    put_robots_to_grid();
    while (robot_count > 1)
        turn();
    for (int i = 0; i < grid_size; i++) // printing rhe name of last robot standing
        for (int j = 0; j < grid_size; j++)
            if (grid[i][j] != NULL)
            {
                cout << "\n\nThe winner is " << grid[i][j]->get_name() << "(" << grid[i][j]->get_hitpoints() << ")" << endl;
                return;
            }
}

/*Function to display the grid */
void Simulation::display()
{
    for (int i = 0; i < grid_size; i++)
    {
        for (int j = 0; j < grid_size; j++)
        {
            if (grid[i][j] == NULL)
                cout << "0";
            else
                cout << "R";
        }
        cout << "\n";
    }
}

/* Function to make move a robot if the robot reaches an empty location int the grid until it meets another robot */
void Simulation::move_until_fight(Robot *r, int i, int j, int dir)
{
    if (!r)
        return ;
    while(1)
    {
        if (dir == 1 && i != 0) // up
        {
            if (grid[i - 1][j] != NULL)
            {
                int which_died = fight_loop(r, grid[i - 1][j]);
                if (which_died == 0)
                {
                    delete grid[i - 1][j];
                    grid[i - 1][j] = NULL;
                    grid[i][j]->set_flag(1); // setting flag of the remaining robot to 1
                }
                else if (which_died == 1)
                {
                    delete grid[i][j];
                    grid[i][j] = NULL;
                    grid[i - 1][j]->set_flag(1);
                }
                return ;
            }
            else // it it doesn't meet a robot, just moves to the target location
            {
                grid[i - 1][j] = grid[i][j];
                grid[i][j] = NULL;
                i = i - 1;
            }
        }
        else if (dir == 2 && j != grid_size - 1) // right
        {
            if (grid[i][j + 1] != NULL)
            {
                int which_died = fight_loop(r, grid[i][j + 1]);
                if (which_died == 0)
                {
                    delete grid[i][j + 1];
                    grid[i][j + 1] = NULL;
                    grid[i][j]->set_flag(1);
                }
                else if (which_died == 1)
                {
                    delete grid[i][j];
                    grid[i][j] = NULL;
                    grid[i][j + 1]->set_flag(1);
                }
                return ;
            }
            else
            {
                grid[i][j + 1] = grid[i][j];
                grid[i][j] = NULL;
                j = j + 1;
            }
        }
        else if (dir == 3 && i != grid_size - 1) // down
        {
            if (grid[i + 1][j] != NULL)
            {
                int which_died = fight_loop(r, grid[i + 1][j]);
                if (which_died == 0)
                {
                    delete grid[i + 1][j];
                    grid[i + 1][j] = NULL;
                    grid[i][j]->set_flag(1);
                }
                else if (which_died == 1)
                {
                    delete grid[i][j];
                    grid[i][j] = NULL;
                    grid[i + 1][j]->set_flag(1);
                }
                return ;
            }
            else
            {
                grid[i + 1][j] = grid[i][j];
                grid[i][j] = NULL;
                i = i + 1;
            }
        }
        else if (dir == 4 && j != 0) //left
        {
            if (grid[i][j - 1] != NULL)
            {
                int which_died = fight_loop(r, grid[i][j - 1]);
                if (which_died == 0)
                {
                    delete grid[i][j - 1];
                    grid[i][j - 1] = NULL;
                    grid[i][j]->set_flag(1);
                }
                else if (which_died == 1)
                {
                    delete grid[i][j];
                    grid[i][j] = NULL;
                    grid[i][j - 1]->set_flag(1);
                }
                return ;
            }
            else
            {
                grid[i][j - 1] = grid[i][j];
                grid[i][j] = NULL;
                j = j - 1;
            }
        }
        dir = rand() % 4 + 1;
    }
}

/* Function to set flags of all robots to zero */
void Simulation::set_flag_to_zero()
{
    for (int i = 0; i < grid_size; i++)
        for (int j = 0; j < grid_size; j++)
            if (grid[i][j] != NULL)
                grid[i][j]->set_flag(0);
}