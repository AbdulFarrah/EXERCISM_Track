#include "hexadecimal.h"
namespace hexadecimal {
// TODO: add your solution here
int convert(const string& s)
{
    int result=0;
    for(unsigned char c : s)
    {
        if(!isdigit(c) && !(tolower(c)=='a' || tolower(c)=='b' || tolower(c)=='c' || tolower(c)=='d' || tolower(c)=='e' || tolower(c)=='f')) return 0;
        int digit = c-'0';
        if(tolower(c)=='a') digit=10;
        else if(tolower(c)=='b') digit=11;
        else if(tolower(c)=='c') digit=12;
        else if(tolower(c)=='d') digit=13;
        else if(tolower(c)=='e') digit=14;
        else if(tolower(c)=='f') digit=15;
        result=(result*16)+digit;
    }
    return result;
}
}  // namespace hexadecimal
