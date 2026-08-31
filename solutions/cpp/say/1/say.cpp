#include "say.h"

namespace say {
// TODO: add your solution here
string in_english(unsigned long long copy)
{
    if (copy>999999999999) throw domain_error("OUT OF RANGE");
    if (copy==0) return "zero";
    string res;
    int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,ten=0,eleven=0,twelve=0;
    if(copy>0)
    {
        one = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        two = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        three = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        four = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        five = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        six = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        seven = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        eight = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        nine = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        ten = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        eleven = copy%10;
        copy=copy/10;
    }
    if(copy>0)
    {
        twelve = copy%10;
        copy=copy/10;
    }
    int billions  = twelve * 100 + eleven * 10 + ten;
int millions  = nine * 100 + eight * 10 + seven;
int thousands = six * 100 + five * 10 + four;
int units      = three * 100 + two * 10 + one;
    if(billions)
{
    res += convert(billions);
    res += " billion";
}

if(millions)
{
    if(!res.empty()) res += " ";
    res += convert(millions);
    res += " million";
}

if(thousands)
{
    if(!res.empty()) res += " ";
    res += convert(thousands);
    res += " thousand";
}

if(units)
{
    if(!res.empty()) res += " ";
    res += convert(units);
}
    return res;
}
string convert(int n)
{
    static string ones[] = {"","one","two","three","four","five","six","seven","eight","nine"};
    static string teens[] = {"ten","eleven","twelve","thirteen","fourteen",
                             "fifteen","sixteen","seventeen","eighteen","nineteen"};
    static string tens[] = {"","","twenty","thirty","forty","fifty",
                            "sixty","seventy","eighty","ninety"};

    string res;

    if (n >= 100) {
        res += ones[n / 100] + " hundred";
        n %= 100;
        if (n) res += " ";
    }

    if (n >= 20) {
        res += tens[n / 10];
        if (n % 10) res += "-" + ones[n % 10];
    }
    else if (n >= 10) {
        res += teens[n - 10];
    }
    else if (n > 0) {
        res += ones[n];
    }

    return res;
}
}  // namespace say
