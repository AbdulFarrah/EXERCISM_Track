#include "alphametics.h"
namespace alphametics {
// TODO: add your solution here
vector<string> split(const string &sep, const string &text)
{
    vector<string> words;
    string::size_type start = 0;
    string::size_type stop = text.find(sep);
    while (stop != string::npos) 
    {
        words.push_back(text.substr(start, stop - start));
        start = stop + sep.size();
        stop = text.find(sep, start);
    }
    words.push_back(text.substr(start));
    return words;
}
void set_weights(int weight[], const vector<string> &words, int sign)
{
    for (auto &word: words) 
    {
       int t = 1;
       for (auto it = word.crbegin(); it != word.crend(); ++it) {
           weight[*it - 'A'] += sign * t;
           t *= 10;
       }
    }
}
void add_leading(bool leaders[], const vector<string> &words)
{
    for (auto &word: words) 
        leaders[word[0] - 'A']=true;
}
optional<unordered_map<unsigned char,int>>
solve(const string &equation)
{
    vector<string> sides = split(" == ", equation);
    vector<string> lhs = split(" + ", sides[0]);
    vector<string> rhs = split(" + ", sides[1]);
    int weight[26] = {};
    set_weights(weight, lhs, 1);
    set_weights(weight, rhs, -1);
    bool leading[26] = {};
    add_leading(leading, lhs);
    add_leading(leading, rhs);
    bool seen[26] = {};
    vector<char> letters;
    vector<int> coeff;
    for(char c : equation)
    {
        if(isalpha(c) && !seen[c-'A'])
        {
            seen[c-'A']=true;
            letters.push_back(c);
        }
    }
    for(char c : letters)
        coeff.push_back(weight[c-'A']);
    vector<pair<int,char>> temp;
    for(size_t i = 0; i < letters.size(); i++)
        temp.push_back({abs(coeff[i]), letters[i]});
    sort(temp.begin(), temp.end(),[](const auto &a, const auto &b){return a.first > b.first;});
    letters.clear();
    coeff.clear();
    for(auto &x : temp)
    {
        letters.push_back(x.second);
        coeff.push_back(weight[x.second-'A']);
    }
    size_t n = letters.size();
    array<bool,10> selector{};
    vector<int> digits(n);
    auto left = selector.begin();
    advance(left, 10 - n);
    fill(left, selector.end(), true);
    do {
        size_t pos = 0;
        for(size_t i = 0; i != 10; i++)
        {
            if(selector[i])
                digits[pos++] = i;
        }
        do {
            bool leading_zero = false;
            int t = 0;
            for (size_t i = 0; i != n; ++i) 
            {
                leading_zero = digits[i] == 0 && leading[letters[i]-'A'];
                if (leading_zero) 
                {
                    break;
                }
                t += digits[i] * coeff[i];
            }
            if (t == 0 && !leading_zero) 
            {
                unordered_map<unsigned char,int> solution;
solution.reserve(n);
                for(size_t i=0;i<n;i++)
                    solution.emplace(letters[i],digits[i]);
                return solution;
            }
        } while (next_permutation(digits.begin(), digits.end()));
    } while (next_permutation(selector.begin(), selector.end()));
    return nullopt;
}
}  // namespace alphametics
