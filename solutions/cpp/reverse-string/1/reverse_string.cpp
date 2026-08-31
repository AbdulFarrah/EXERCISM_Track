#include "reverse_string.h"

namespace reverse_string {
// TODO: add your solution here
string reverse_string(const string& s)
{
    if(s.empty()) return "";
    return string(s.rbegin(),s.rend());
} 
}  // namespace reverse_string
