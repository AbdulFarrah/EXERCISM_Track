#include "roman_numerals.h"
namespace roman_numerals {
unordered_map<int, string> arabroman = {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {4, "IV"},
    {5, "V"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"},
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {40, "XL"},
    {50, "L"},
    {60, "LX"},
    {70, "LXX"},
    {80, "LXXX"},
    {90, "XC"},
    {100, "C"},
    {200, "CC"},
    {300, "CCC"},
    {400, "CD"},
    {500, "D"},
    {600, "DC"},
    {700, "DCC"},
    {800, "DCCC"},
    {900, "CM"},
    {1000, "M"},
    {2000, "MM"},
    {3000, "MMM"}
};
string convert(int num)
{
    string result;
    int thousand = (num / 1000) * 1000;
    int hundred  = ((num % 1000) / 100) * 100;
    int ten      = ((num % 100) / 10) * 10;
    int one      = num % 10;
    if (thousand) result += arabroman[thousand];
    if (hundred)  result += arabroman[hundred];
    if (ten)      result += arabroman[ten];
    if (one)      result += arabroman[one];
    return result;
}
}  // namespace roman_numerals
