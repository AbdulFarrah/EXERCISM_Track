#include "nucleotide_count.h"
namespace nucleotide_count {
// TODO: add your solution here
const map<char,int> count(const string& A)
{
    map<char,int> res{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for(auto it : A)
        if(it == 'A' || it == 'G' || it == 'C' || it == 'T')
            res[it]++;
        else
            throw::invalid_argument("");
    return res;
}
}  // namespace nucleotide_count
