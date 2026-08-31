#include "all_your_base.h"
namespace all_your_base {
const vector<unsigned int> convert(unsigned int from,const vector<unsigned int>& digits,unsigned int to)
{
    if (from < 2 || to < 2)
        throw invalid_argument("");
    for (auto digit : digits)
        if (digit >= from)
            throw invalid_argument("");
    unsigned int number = 0;
    for (auto digit : digits)
        number = number * from + digit;
    if (number == 0)
        return {};
    vector<unsigned int> result;
    while (number)
    {
        result.push_back(number % to);
        number /= to;
    }
    reverse(result.begin(), result.end());
    return result;
}
} // namespace all_your_base