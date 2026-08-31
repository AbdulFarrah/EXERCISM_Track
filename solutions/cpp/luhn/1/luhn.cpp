#include "luhn.h"
namespace luhn {
// TODO: add your solution here
bool valid(const string& str)
{
    string s;
    for(unsigned char c : str)
    {
        if(!isspace(c)) s+=c;
    }
    if (s.size()<2) return false;
    int sum=0,place=1;
    for(int i=static_cast<int>(s.size())-1;i>=0;i--)
    {
        if(!isdigit(s[i]) && !isspace(s[i])) return false;
        else
        {
            if(place%2==0)
            {
                int temp= (s[i]-'0')*2;
                if(temp>9) temp-=9;
                sum+=temp;
            }
            else
                sum+=(s[i]-'0');
            place++;   
        }
    }
    return !(sum%10);
}
}  // namespace luhn
