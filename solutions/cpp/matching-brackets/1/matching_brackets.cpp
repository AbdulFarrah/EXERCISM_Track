#include "matching_brackets.h"
namespace matching_brackets {
// TODO: add your solution here
bool check(const string& s)
{
    stack<unsigned char> result;
    for(unsigned char c : s)
    {
    if(c=='{' || c=='}' || c=='(' || c==')' || c=='[' || c==']')
    {
    switch(c)
    {
    case '{': result.push(c); break;
    case '[': result.push(c); break;
    case '(': result.push(c); break;
    case '}':
    if(result.empty() || result.top() != '{')
        return false;
    result.pop();
    break;
case ']':
    if(result.empty() || result.top() != '[')
        return false;
    result.pop();
    break;
case ')':
    if(result.empty() || result.top() != '(')
        return false;
    result.pop();
    break;
    }
    }
    }
    return result.empty();
}
}  // namespace matching_brackets
