#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <algorithm>
#include <optional>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <array>
using namespace std;
namespace alphametics {
// TODO: add your solution here
optional<unordered_map<unsigned char,int>> solve(const string&);
}  // namespace alphametics

#endif  // ALPHAMETICS_H
