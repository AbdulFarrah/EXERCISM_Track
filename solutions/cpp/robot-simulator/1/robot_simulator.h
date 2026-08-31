#pragma once
#include <string>
using namespace std;
namespace robot_simulator {
enum class Bearing{NORTH,SOUTH,EAST,WEST};
class Robot{
public:
    int xcord;
    int ycord;
    robot_simulator::Bearing Dir;
    Robot();
    Robot(const pair<int,int>,robot_simulator::Bearing);
    pair<int,int> get_position() const;
    robot_simulator::Bearing get_bearing() const;
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const string&);
};
// TODO: add your solution here

}  // namespace robot_simulator
