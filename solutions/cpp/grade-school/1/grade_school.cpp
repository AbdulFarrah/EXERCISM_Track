#include "grade_school.h"

namespace grade_school {
// TODO: add your solution here
map<int,vector<string>> school::roster() const
{
    return class_roster;
}
void school::add(const string& name,int grade)
{
    for(auto& [k,v] : class_roster)
    {
        for(auto& n:v)
        {
            if(n==name) return;
        }
    }
    class_roster[grade].push_back(name);
    for (auto& [k, v] :class_roster ) 
    {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }
}
vector<string> school::grade(int grade) const
{
     for (auto& [k, v] :class_roster ) 
    {
        if(k==grade) return v;
    }
    vector<string> res;
    return res;
}
}  // namespace grade_school
