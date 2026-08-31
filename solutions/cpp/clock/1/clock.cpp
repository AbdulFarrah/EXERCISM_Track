#include "clock.h"
namespace date_independent {
// TODO: add your solution here
clock::clock(int min)
{
    if(min < 0) minutes = 1440 + min%1440;
    else minutes = min % 1440;
}
clock clock::at(int hour, int minute)
{
    return clock((hour*60)+minute);
}
clock clock::plus(int min) const
{
    return clock(minutes+min);
}
clock::operator std::string() const
{
    ostringstream ss;
    ss << setfill('0') << setw(2) << minutes/60 << ":" << setw(2) << minutes%60;
    return ss.str();
}  
bool clock::operator==(const clock& other) const
{
    return minutes == other.minutes;
}
bool clock::operator!=(const clock& other) const
{
    return minutes != other.minutes;
}
}  // namespace date_independent
