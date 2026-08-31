#include "knapsack.h"
namespace knapsack {
// TODO: add your solution here
int maximum_value(int maxweight, const vector<Item>& items)
{
    int result = 0;
    for (int mask = 0; mask < (1 << items.size()); mask++)
    {
        int weight = 0;
        int value = 0;
        for (size_t i = 0; i < items.size(); i++)
        {
            if (mask & (1 << i))
            {
                weight += items[i].weight;
                value += items[i].value;
            }
        }
        if (weight <= maxweight && value > result)
            result = value;
    }
    return result;
}
}  // namespace knapsack
