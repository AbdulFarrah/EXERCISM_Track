#include "armstrong_numbers.h"
namespace armstrong_numbers {
// TODO: add your solution here
bool is_armstrong_number(int num)
{
    string s = to_string(num);
    int digits = s.size(),sum = 0;
    for (unsigned char c : s)
    {
        int digit = c - '0';
        int p = 1;
        for (int i = 0; i < digits; ++i)
            p *= digit;
        sum += p;
    }
    return sum == num;
}
}  // namespace armstrong_numbers
