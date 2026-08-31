#include "series.h"

namespace series {
// TODO: add your solution here
const vector<string> slice(string s,size_t i)
{
    if(s.empty() || i <= 0 || i>s.size())throw::domain_error("");
    vector<string> results;
    size_t start=0;
    while((start+i) <= s.size())
    {
        results.push_back(s.substr(start,i));
        start++;
    }
    return results;
}
}  // namespace series
