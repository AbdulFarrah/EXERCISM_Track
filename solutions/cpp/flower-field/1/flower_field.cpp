#include "flower_field.h"
namespace flower_field {
// TODO: add your solution here
const vector<string> annotate(const vector<string>& pattern)
{
    if(pattern.size()==0) return {};
    bool has_blank=false,has_flower=false;
    for(auto it : pattern)
    {
        for(unsigned char c: it)
        {
            if(c==' ') has_blank=true;
            if(c=='*') has_flower=true;
        }
    }
    if(!(has_blank&&has_flower)) return pattern;
    vector<string> result = pattern;
    for (size_t x = 0; x < pattern.size(); ++x)
    {
    for (size_t y = 0; y < pattern[x].size(); ++y)
    {
        if (pattern[x][y] == '*')
            continue;
        int count = 0;
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                size_t nx = x + dx;
                size_t ny = y + dy;
                if (nx < pattern.size() && ny < pattern[nx].size() && pattern[nx][ny] == '*')
                {
                    ++count;
                }
            }
        }
        if (count > 0)
            result[x][y] = '0' + count;
    }
    }
    return result;
}
}  // namespace flower_field
