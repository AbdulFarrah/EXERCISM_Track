#include "affine_cipher.h"
namespace affine_cipher {
// TODO: add your solution here
const string encode(const string& text,int a,int b)
{
    if(!(gcd(a, 26) == 1)) throw::invalid_argument("");
    string result;
    int charcount=0;
    for(unsigned char c : text)
        if(isalpha(c))
        {
            if(charcount>0&&charcount%5==0)result+=' ';
            result+=((a*(tolower(c)-'a')+b)%26)+'a';
            charcount++;
        }
        else if(isdigit(c))
        {
            if(charcount>0&&charcount%5==0)result+=' ';
            result+=c;
            charcount++;
        }
    return result;
}
const string decode(const string& text,int a,int b)
{
    if(!(gcd(a, 26) == 1)) throw::invalid_argument("");
    string result;
    int x;
    for (x = 0; x < 26; x++)
        if ((a * x) % 26 == 1)
            break;
    for(unsigned char c : text)
        if(isalpha(c))
        {
            int value=(x*((c-'a')-b)%26);
            if (value<0) value+=26;
            result+=value+'a';
        }
        else if(isdigit(c))
            result+=c;
    return result;
}
}  // namespace affine_cipher
