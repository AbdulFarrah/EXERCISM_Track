#pragma once
#include <vector>
#include <string_view>
#include <unordered_map>
using namespace std;
namespace parallel_letter_frequency {
void worker(const vector<string_view>&,size_t,size_t,unordered_map<char,int>&);
const unordered_map<char,int> frequency(const vector<string_view>&);
}
