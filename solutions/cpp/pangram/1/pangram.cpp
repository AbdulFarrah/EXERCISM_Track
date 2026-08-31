#include "pangram.h"

namespace pangram {
// TODO: add your solution here
bool is_pangram(string s)
{
    set<char> letters;
    for (char c : s)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
            letters.insert(std::tolower(static_cast<unsigned char>(c)));
    }
    return letters.size()==26;
}
}  // namespace pangram
