#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
namespace allergies {
// TODO: add your solution here
class allergy_test{
    public:
        allergy_test(int);
        int allergy_score=0;
        unordered_map<string,int> allergy_map;
        bool is_allergic_to(const string&);
        unordered_set<string> get_allergies();
};
}  // namespace allergies
