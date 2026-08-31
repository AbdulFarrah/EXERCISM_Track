#include "largest_series_product.h"
namespace largest_series_product {
// TODO: add your solution here
size_t largest_product(const string& pattern,size_t span)
{
    if(pattern.size()<span) throw::domain_error("");
    if(span<1) throw::domain_error("");
    for(unsigned char c : pattern)
        if(!isdigit(c)) throw::domain_error("");
    size_t start=0,stop=span-1,max=0;
    while(stop<pattern.size())
    {
        size_t temp=1;
        for(size_t i=start;i<=stop;i++)
            temp*=stoi(string(1,pattern[i]));
        if(max<temp)
            max=temp;
        start++;
        stop++;
    }
    return max;
}
}  // namespace largest_series_product
