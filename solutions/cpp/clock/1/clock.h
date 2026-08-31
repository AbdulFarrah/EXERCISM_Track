#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
namespace date_independent {
class clock{
    int minutes;
    public:
        clock(int);
        static clock at(int hour, int minute);
        clock plus(int min) const;
        operator std::string() const;
        bool operator==(const clock&) const;
        bool operator!=(const clock&) const;
};
// TODO: add your solution here

}  // namespace date_independent
