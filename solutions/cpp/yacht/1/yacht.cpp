#include "yacht.h"
namespace yacht {
// TODO: add your solution here
int score(const vector<int>& dice,const string& category)
{
    int freq[7] = {};
    int sum = 0;
    for (int x : dice)
    {
        freq[x]++;
        sum += x;
    }
    int face = 0;
    if (category == "ones") face = 1;
    else if (category == "twos") face = 2;
    else if (category == "threes") face = 3;
    else if (category == "fours") face = 4;
    else if (category == "fives") face = 5;
    else if (category == "sixes") face = 6;
    if (face) return freq[face] * face;
    if(category=="choice") return sum;
    if(category == "yacht") if (freq[dice[0]] == 5) return 50;
    if(category == "full house")
    {
        bool has2 = false, has3 = false;
        for (int i = 1; i <= 6; i++)
        {
            has2 |= freq[i] == 2;
            has3 |= freq[i] == 3;
        }
        return (has2 && has3) ? sum : 0;
    }
    if(category == "four of a kind")
    {
        for (int i = 1; i <= 6; i++)
            if (freq[i] >= 4)
                return i * 4;
    }
    if(category == "little straight")
    {
        bool ok = true;
        for (int i = 1; i <= 5; i++)
            ok &= freq[i] == 1;
        if (ok) return 30;
    }
    if(category == "big straight")
    {
        bool ok = true;
        for (int i = 2; i <= 6; i++)
            ok &= freq[i] == 1;
        if (ok) return 30;
    }
    return 0;
}
}  // namespace yacht
