#include "grains.h"

namespace grains {

// TODO: add your solution here
unsigned long long square(int sqr)
{
    unsigned long long result=1;
    for(int i = 1;i<sqr;i++)
        {
            result=result*2;
        }
    return result;
}
unsigned long long total()
{
    unsigned long long result=0;
    for(int i=1;i<=64;i++)
    {
        result+=square(i);
    }
    return result;
}
}  // namespace grains
