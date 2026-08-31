#include "allergies.h"
namespace allergies {
// TODO: add your solution here
allergy_test::allergy_test(int score)
{
    allergy_score = score;
    allergy_map["eggs"]=1;
    allergy_map["peanuts"]=2;
    allergy_map["shellfish"]=4;
    allergy_map["strawberries"]=8;
    allergy_map["tomatoes"]=16;
    allergy_map["chocolate"]=32;
    allergy_map["pollen"]=64;
    allergy_map["cats"]=128;
}
bool allergy_test::is_allergic_to(const string& name)
{
    return (allergy_score & allergy_map[name]) != 0;
}
unordered_set<string> allergy_test::get_allergies()
{
    unordered_set<string> result;
    for (const auto& [key,value] : allergy_map)
    {
        if(is_allergic_to(key)) result.emplace(key);
    }
    return result;
}
}  // namespace allergies
