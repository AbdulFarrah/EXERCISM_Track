#include "eliuds_eggs.h"
namespace chicken_coop {
// TODO: add your solution here
int positions_to_quantity(long long num)
{
    int eggs = 0;
    while (num > 0)
    {
        if (num % 2) eggs++;
        num /= 2;
    }
    return eggs;
}
}  // namespace chicken_coop
