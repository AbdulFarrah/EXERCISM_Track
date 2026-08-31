#include "pascals_triangle.h"
namespace pascals_triangle {
// TODO: add your solution here
vector<vector<int>> generate_rows(int n)
{
    if(n==0) return {};
    vector<vector<int>> result;
    for(int i=0;i<n;i++)
    {
        vector<int> row(i+1);
        row[0] = 1;
        for (int k = 1; k <= i; ++k)
            row[k] = row[k - 1] * (i - k + 1) / k;
        result.push_back(row);
    }
    return result;
}
}  // namespace pascals_triangle
