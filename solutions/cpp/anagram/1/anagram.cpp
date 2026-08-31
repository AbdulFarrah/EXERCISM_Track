#include "anagram.h"
namespace anagram {
// TODO: add your solution here
anagram::anagram(string s)
{
      transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    orgword=s;
    sort(s.begin(), s.end());
do { result.insert(s); } while (next_permutation(s.begin(), s.end()));
}
const unordered_set<string> anagram::matches(const vector<string>& vals)
{
    unordered_set<string> res;
    for(const auto& it:vals)
    {
        string temp = it;

        transform(temp.begin(), temp.end(), temp.begin(),
                  [](unsigned char c) { return tolower(c); });

        if(result.find(temp)!=result.end() && temp!=orgword)
            res.insert(it);
    }
    return res;
}
}  // namespace anagram
