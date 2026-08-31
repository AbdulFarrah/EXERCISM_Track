#include "diamond.h"
namespace diamond {
// TODO: add your solution here
vector<string> rows(unsigned char c)
{
    int n = c - 'A' + 1,size = 2 * n - 1;  
    vector<string> result(size, string(size, ' '));
    for (int i = 0; i < n; i++)
    {
    char ch = 'A' + i;
    int r1 = i;
    int r2 = size - 1 - i;
    int c1 = n - 1 - i;
    int c2 = n - 1 + i;
    result[r1][c1] = ch;
    result[r1][c2] = ch;
    result[r2][c1] = ch;
    result[r2][c2] = ch;
    }
    return result;
}
}  // namespace diamond
