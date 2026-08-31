#include "isogram.h"
namespace isogram {
// TODO: add your solution here
bool is_isogram(const string& s)
{
    int letters[26]={0};
    for(unsigned char c : s)
        if(isalpha(c))
        {
            if(letters[tolower(c)-'a']==1) return false;
            else letters[tolower(c)-'a']=1;
        }
    return true;
}
}  // namespace isogram
