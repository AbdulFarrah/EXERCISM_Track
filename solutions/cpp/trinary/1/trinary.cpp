#include "trinary.h"
namespace trinary {
// TODO: add your solution here
unsigned long to_decimal(const string& num)
{
    unsigned long result=0;
    for(unsigned char c: num)
    {
        if(!isdigit(c)) return 0;
        result=(result*3)+(c-'0');
    }
    return result;
}
}  // namespace trinary
