#include "sum_of_multiples.h"
namespace sum_of_multiples {
// TODO: add your solution here
int to(const vector<int>& base,int level)
{
    int result=0;
    if(level==0 || base.empty()) return result;
    unordered_set<int> multiples;
    for (int it : base)
    {
        int i = 1;
        while (true)
        {
            int multiple = it * i;
            if (multiple >= level) break;
            multiples.insert(multiple);
            ++i;
        }
    }
    for(int it : multiples)
        result+=it;
    return result;
}
}  // namespace sum_of_multiples
