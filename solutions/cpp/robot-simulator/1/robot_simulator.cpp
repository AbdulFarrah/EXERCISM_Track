#include "robot_simulator.h"
namespace robot_simulator {
// TODO: add your solution here
Robot::Robot()
{
    xcord=0;
    ycord=0;
    Dir=Bearing::NORTH;
}
Robot::Robot(const pair<int,int> cordinates,robot_simulator::Bearing Direction)
{
    xcord=cordinates.first;
    ycord=cordinates.second;
    Dir=Direction;
}
pair<int,int> Robot::get_position() const
{
    pair<int,int> result{xcord,ycord};
    return result;
}
robot_simulator::Bearing Robot::get_bearing() const
{
    return Dir;
}
void Robot::turn_right()
{
    switch(Dir)
    {
        case Bearing::NORTH: Dir=Bearing::EAST;break;
        case Bearing::EAST: Dir=Bearing::SOUTH;break;
        case Bearing::SOUTH: Dir=Bearing::WEST;break;
        case Bearing::WEST: Dir=Bearing::NORTH;break;
    }
}
void Robot::turn_left()
{
    switch(Dir)
    {
        case Bearing::NORTH: Dir=Bearing::WEST;break;
        case Bearing::EAST: Dir=Bearing::NORTH;break;
        case Bearing::SOUTH: Dir=Bearing::EAST;break;
        case Bearing::WEST: Dir=Bearing::SOUTH;break;
    }
}
void Robot::advance()
{
    switch(Dir)
    {
        case Bearing::NORTH: ycord++;break;
        case Bearing::EAST: xcord++;break;
        case Bearing::SOUTH: ycord--;break;
        case Bearing::WEST: xcord--;break;
    }
}
void Robot::execute_sequence(const string& pattern)
{
    for(unsigned char c : pattern)
    {
        switch(c)
            {
                case 'R': turn_right();break;
                case 'L': turn_left();break;
                case 'A': advance();break;
            }
    }
}
}  // namespace robot_simulator
