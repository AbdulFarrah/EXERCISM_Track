#pragma once
#include <vector>
using namespace std;
namespace sublist {
// TODO: add your solution here
enum class List_comparison{equal,sublist,superlist,unequal};
List_comparison sublist(const vector<int>&,const vector<int>&);
bool contains(const vector<int>& , const vector<int>&);
}  // namespace sublist
