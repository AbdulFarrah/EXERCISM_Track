#include "pig_latin.h"
namespace pig_latin {
// TODO: add your solution here
const string translate(const string& word)
{
    istringstream iss(word);
    string it, result;
    while (iss >> it)
    {
        size_t pos = 0;
        if (it[0] == 'a' || it[0] == 'e' || it[0] == 'i' ||
            it[0] == 'o' || it[0] == 'u' ||
            it.substr(0, 2) == "xr" || it.substr(0, 2) == "yt")
        {
            result += it + "ay";
        }
        else
        {
            while (pos < it.size())
            {
                if (pos + 1 < it.size() &&
                    it[pos] == 'q' && it[pos + 1] == 'u')
                {
                    pos += 2;
                    break;
                }
                if (it[pos] == 'a' || it[pos] == 'e' ||
                    it[pos] == 'i' || it[pos] == 'o' ||
                    it[pos] == 'u')
                    break;
                if (it[pos] == 'y' && pos > 0)
                    break;
                pos++;
            }
            result += it.substr(pos) + it.substr(0, pos) + "ay";
        }
        result += " ";
    }
    if (!result.empty())
        result.pop_back();
    return result;
}
}  // namespace pig_latin
