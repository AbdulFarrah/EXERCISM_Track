#include "run_length_encoding.h"
namespace run_length_encoding {
// TODO: add your solution here
string encode(const string& s)
{
    string result;
    for(size_t i=0;i<s.size();i++)
    {
        if(isalpha(s[i]) || isspace(s[i]))
        {
            int count=1;
            while(i + 1 < s.size() && s[i]==s[i+1])
            {
                count++;
                i++;
            }
            if(count>1)
            {
                result+=to_string(count)+s[i];
            }
            else result+=s[i];
        }
    }
    return result;
}
string decode(const string& s)
{
    string result;
    for(size_t i=0;i<s.size();i++)
    {
        string digit;
        if(isdigit(s[i]))
        {
        while(i<s.size() && isdigit(s[i]))
        {
            digit+=s[i];
            i++;
        }
        result.append(stoi(digit), s[i]);
        }
        else result+=s[i];
    }
    return result;
}
}  // namespace run_length_encoding
