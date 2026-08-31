#include "binary.h"
namespace binary {
// TODO: add your solution here
int convert(const string& s)
{
    int result=0;
    for(unsigned char c : s)
    {
        if(!isdigit(c)) return 0;
        result=(result*2)+(c-'0');
    }
    return result;
}
}  // namespace binary
