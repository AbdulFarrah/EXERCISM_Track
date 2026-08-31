#include "acronym.h"
namespace acronym {
// TODO: add your solution here
const string acronym(const string& s)
{
    string result;
    result+=toupper(s[0]);
    for(size_t i =1;i<s.size();i++)
    {
        if(s[i]==' ' || s[i]=='-')
        {
            size_t j=i;
            while(j<s.size() && !isalpha(s[j]))
                j++;
            result+= toupper(s[j]);
            i=j-1;
        }
    }
    return result;
}
}  // namespace acronym
