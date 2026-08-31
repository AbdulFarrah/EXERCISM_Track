#include "resistor_color_duo.h"
namespace resistor_color_duo {
// TODO: add your solution here
int value(const vector<string>& s)
{
    int result=0;
    if(s.size()<2) return result;
    for(int i=0;i<2;i++)
    {
        if(s[i] == "black") result=result*10+0; 
        else if(s[i] == "brown") result=result*10+1;
        else if(s[i] == "red") result=result*10+2;
        else if(s[i] == "orange") result=result*10+3;
        else if(s[i] == "yellow") result=result*10+4;
        else if(s[i] == "green") result=result*10+5;
        else if(s[i] == "blue") result=result*10+6;
        else if(s[i] == "violet") result=result*10+7;
        else if(s[i] == "grey") result=result*10+8;
        else if(s[i] == "white") result=result*10+9;
    }
    return result;
}
}  // namespace resistor_color_duo
