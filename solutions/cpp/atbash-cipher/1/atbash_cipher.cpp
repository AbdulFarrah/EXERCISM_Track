#include "atbash_cipher.h"
namespace atbash_cipher {
// TODO: add your solution here
const string encode(const string& s)
{
    string result;
    int validcharcount=0;
    for(unsigned char c : s)
    {
        if(isalpha(c))
        {
            result+= (25 - (tolower(c)-'a'))+'a';
            validcharcount++;
            if(validcharcount%5==0) result+=' ';
        }
        if(isdigit(c))
        {
            result+=c;
            validcharcount++;
            if(validcharcount%5==0) result+=' ';
        }
    }
    if(result[result.size()-1]==' ') result.pop_back();
    return result;
}
const string decode(const string& s)
{
    string result;
    for(unsigned char c : s)
    {
        if(isalpha(c)) result+= (25 - (c-'a'))+'a';
        if(isdigit(c)) result+=c;
    }
    return result;
}
}  // namespace atbash_cipher
