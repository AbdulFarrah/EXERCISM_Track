#pragma once
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
namespace grade_school {
// TODO: add your solution here
class school
{
    public:
    map<int,vector<string>> class_roster;
    map<int,vector<string>> roster() const;
    void add(const string&,int);
    vector<string> grade(int) const;
};
}  // namespace grade_school
