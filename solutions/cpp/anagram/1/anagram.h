#pragma once
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype>
using namespace std;
namespace anagram {
// TODO: add your solution here
class anagram{
    public:
        anagram(string);
        const unordered_set<string> matches(const vector<string>&);
    unordered_set<string> result;
    string orgword;
};
}  // namespace anagram
