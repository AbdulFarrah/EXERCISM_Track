#include "raindrops.h"

namespace raindrops {
// TODO: add your solution here
string convert(int num)
{
    string result="";
    if(num%3==0) result += "Pling";
    if(num%5==0) result += "Plang";
    if(num%7==0) result += "Plong";
    if (result=="") return to_string(num);
    return result;
}
}  // namespace raindrops
