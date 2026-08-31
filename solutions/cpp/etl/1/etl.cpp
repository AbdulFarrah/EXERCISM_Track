#include "etl.h"
namespace etl {
// TODO: add your solution here
const map<char,int> transform(const map<int,vector<char>>& A)
{
    map<char,int> result;
    for(const auto& [key,value] : A)
        for(const auto& val : value)
            result[tolower(val)]=key;
    return result;
        
}
}  // namespace etl
