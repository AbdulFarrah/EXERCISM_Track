#include "secret_handshake.h"
namespace secret_handshake {
// TODO: add your solution here
const vector<string> commands(int num)
{
    vector<string> result;
    int one=0,two=0,three=0,four=0,five=0;
    if(num>0)
    {
        one=num%2;
        num=num/2;
    }
    if(num>0)
    {
        two=num%2;
        num=num/2;
    }
    if(num>0)
    {
        three=num%2;
        num=num/2;
    }
    if(num>0)
    {
        four=num%2;
        num=num/2;
    }
    if(num>0)
    {
        five=num%2;
        num=num/2;
    }
    if(five)
    {
        if(four)result.push_back("jump");
        if(three)result.push_back("close your eyes");
        if(two)result.push_back("double blink");
        if(one)result.push_back("wink");
    }
    else
    {
        if(one)result.push_back("wink");
        if(two)result.push_back("double blink");
        if(three)result.push_back("close your eyes");
        if(four)result.push_back("jump");
    }
    return result;
}
}  // namespace secret_handshake
