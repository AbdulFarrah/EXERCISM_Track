#pragma once
#include<vector>
using namespace std;
namespace knapsack {
struct Item {
    int weight;
    int value;
};
int maximum_value(int,const vector<Item>&);
}  // namespace knapsack
