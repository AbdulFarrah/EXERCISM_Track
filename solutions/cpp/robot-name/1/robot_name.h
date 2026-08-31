#pragma once
#include <string>
using namespace std;
namespace robot_name {
// TODO: add your solution here
class robot{
    public:
    robot();
    string name() const;
    string robotname;
    void reset();
    string generatename();
};
}  // namespace robot_name
