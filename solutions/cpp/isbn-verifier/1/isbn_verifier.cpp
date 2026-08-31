#include "isbn_verifier.h"
namespace isbn_verifier {
// TODO: add your solution here
bool is_valid(const string& s)
{
    string str;
    for (unsigned char c : s)
    {
        if (isdigit(c) || c == 'X')
            str += c;
        else if (c != '-')
            return false;
    }
    if(str.size()!=10) return false;

    size_t pos = str.find('X');
    if (pos != string::npos && pos != str.size() - 1) 
        return false;
    
    int sum=0,place=10;
    for(unsigned char  c : str)
    {
        if(c=='X')
            sum+=10;
        else
            sum+=(c-'0')*place;
        place--;
    }
    return !(sum%11);
}
}  // namespace isbn_verifier
