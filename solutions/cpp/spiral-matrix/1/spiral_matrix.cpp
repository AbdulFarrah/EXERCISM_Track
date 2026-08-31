#include "spiral_matrix.h"
namespace spiral_matrix {
// TODO: add your solution here
const vector<vector<uint32_t>> spiral_matrix(uint32_t num)
{
    if (num == 0) return {};
    vector<vector<uint32_t>> result(num, vector<uint32_t>(num));
    uint32_t val = 1;
    int row = 0, col = 0;
    while (val <= num * num)
    {
        while (col < static_cast<int>(num) && result[row][col] == 0)
            result[row][col++] = val++;
        col--;
        row++;
        while (row < static_cast<int>(num) && result[row][col] == 0)
            result[row++][col] = val++;
        row--;
        col--;
        while (col >= 0 && result[row][col] == 0)
            result[row][col--] = val++;
        col++;
        row--;
        while (row >= 0 && result[row][col] == 0)
            result[row--][col] = val++;
        row++;
        col++;
    }
    return result;
}
}  // namespace spiral_matrix
