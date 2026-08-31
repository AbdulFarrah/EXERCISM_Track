#include "sublist.h"
namespace sublist {
bool contains(const vector<int>& small, const vector<int>& large)
{
    if (small.size() > large.size())
        return false;
    for (size_t i = 0; i <= large.size() - small.size(); ++i)
    {
        size_t j = 0;
        while (j < small.size() && small[j] == large[i + j])
            ++j;
        if (j == small.size())
            return true;
    }
    return false;
}

List_comparison sublist(const vector<int>& A, const vector<int>& B)
{
    if (A == B)
        return List_comparison::equal;
    if (A.size() < B.size() && contains(A, B))
        return List_comparison::sublist;
    if (A.size() > B.size() && contains(B, A))
        return List_comparison::superlist;
    return List_comparison::unequal;
}
}  // namespace sublist