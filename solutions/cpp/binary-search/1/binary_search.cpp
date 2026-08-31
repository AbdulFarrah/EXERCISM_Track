#include "binary_search.h"
namespace binary_search {
// TODO: add your solution here
int find(const vector<int>& arr, int val)
{
    if (arr.empty() || val < arr[0] || val > arr.back())
        throw domain_error("");
    int lower = 0;
    int higher = arr.size() - 1;
    while (lower <= higher)
    {
        int middle = lower + (higher - lower) / 2;
        if (arr[middle] == val)
            return middle;
        if (arr[middle] > val)
            higher = middle - 1;
        else
            lower = middle + 1;
    }
    throw domain_error("");
}
}  // namespace binary_search
