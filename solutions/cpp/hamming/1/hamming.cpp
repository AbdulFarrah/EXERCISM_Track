#include "hamming.h"
namespace hamming {
// TODO: add your solution here
size_t compute(const string& A,const string& B)
{
    size_t length = A.size();
    if(length!=B.size()) throw::domain_error("");
    size_t difference=0;
    for(size_t i=0;i<length;i++)
        if(A[i]!=B[i])
            difference++;
    return difference;
}
}  // namespace hamming
