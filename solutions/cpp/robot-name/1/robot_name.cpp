#include "robot_name.h"

namespace robot_name {
// TODO: add your solution here
robot::robot()
{
    robotname = generatename();
}
string robot::name() const
{
    return robotname;
}
void robot::reset()
{
    robotname=generatename();
}
string robot::generatename()
{
    static unsigned counter = 0;

unsigned value = counter++;

int number = value % 1000;
value /= 1000;

int second = value % 26;
value /= 26;

int first = value % 26;

std::string s;
s += char('A' + first);
s += char('A' + second);

s += char('0' + number / 100);
s += char('0' + (number / 10) % 10);
s += char('0' + number % 10);

return s;
}
}  // namespace robot_name
