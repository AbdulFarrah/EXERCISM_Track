#include "collatz_conjecture.h"
namespace collatz_conjecture {
// TODO: add your solution here
int steps(int num)
{
    if(num<=0)throw::domain_error("");
    int result=0;
    while(num!=1)
    {
        if(num%2==0)
        {
            num/=2;
            result++;
        }
        else 
        {
            num=(num*3)+1;
            result++;
        }
    }
    return result;
}
}  // namespace collatz_conjecture
