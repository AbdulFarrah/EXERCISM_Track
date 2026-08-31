#include "phone_number.h"
namespace phone_number {
// TODO: add your solution here
phone_number::phone_number(string s)
{
    s.erase(std::remove_if(s.begin(), s.end(),
        [](unsigned char c){ return !std::isdigit(c); }), s.end());
    if (s.size() == 11 && s.front() == '1') s.erase(s.begin());
    if(s.size()==11 && s.front()!='1')throw::domain_error(""); 
    if(s.size()!=10) throw::domain_error("");
    if(s.front()=='0' ||s.front()=='1')throw::domain_error("");
    if(s[3] == '0' || s[3] == '1') throw::domain_error("");
    num=s;
}
string phone_number::number()
{
    return num;
}
}  // namespace phone_number
