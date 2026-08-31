#include "word_count.h"
namespace word_count {
// TODO: add your solution here
const map<string,int> words(const string& s)
{
    map<string, int> words;
    string word;
    for (size_t i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (isalpha(static_cast<unsigned char>(c)) ||
            isdigit(static_cast<unsigned char>(c)))
        {
            word += tolower(static_cast<unsigned char>(c));
        }
        else if (c == '\'' &&
                 !word.empty() &&
                 i + 1 < s.size() &&
                 isalnum(static_cast<unsigned char>(s[i + 1])))
        {
            word += '\'';
        }
        else
        {
            if (!word.empty())
            {
                ++words[word];
                word.clear();
            }
        }
    }
    if (!word.empty())
        ++words[word];
    return words;
}
}  // namespace word_count
