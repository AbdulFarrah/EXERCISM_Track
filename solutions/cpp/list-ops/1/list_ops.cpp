#include "list_ops.h"
namespace list_ops {
// TODO: add your solution here
void append(vector<int>& A, const vector<int>& B)
{
    for(auto it : B)
        A.push_back(it);
}
const vector<int> concat(const vector<vector<int>>& A)
{
    vector<int>result;
    for(auto it : A)
        for(auto it1 : it)
            result.push_back(it1);
    return result;
}
const vector<vector<int>> concat(const vector<vector<vector<int>>>& A)
{
    vector<vector<int>>result;
    for(auto it : A)
        for(auto it1 : it)
            result.push_back(it1);
    return result;
}
const vector<int> filter(const vector<int>& A,const function<bool(int)>& func)
{
    vector<int> result;
    for(auto it : A)
        if(func(it))
            result.push_back(it);
    return result;
}
size_t length(const vector<int>& A)
{
    int count=0;
    for (auto it = A.begin(); it != A.end(); ++it)
        count++;
    return count;
}
const vector<int> map(const vector<int>& A,const function<int(int)>& func)
{
    vector<int> result;
    for(auto it : A)
        result.push_back(func(it));
    return result;
}
int foldl(const vector<int>& A,int acc,const function<int(int,int)>& func)
{
    int result=acc;
    for(auto it : A)
        result=func(it,result);
    return result;
}
double foldl(const vector<double>& A,double acc,const function<double(double,double)>& func)
{
    double result=acc;
    for(auto it : A)
        result=func(result,it);
    return result;
}
int foldr(const vector<int>& A,int acc,const function<int(int,int)>& func)
{
    int result=acc;
    for (auto it = A.rbegin(); it != A.rend(); ++it)
        result = func(result, *it);
    return result;
}
double foldr(const vector<double>& A,double acc,const function<double(double,double)>& func)
{
    double result=acc;
    for (auto it = A.rbegin(); it != A.rend(); ++it)
        result = func(result, *it);
    return result;
}
const vector<int> reverse(const vector<int>& A)
{
    vector<int> result;
    for (auto it = A.rbegin(); it != A.rend(); ++it)
        result.push_back(*it);
    return result;
}
const vector<vector<int>> reverse(const vector<vector<int>>& A)
{
    vector<vector<int>> result;
    for (auto it = A.rbegin(); it != A.rend(); ++it)
        result.push_back(*it);
    return result;
}
}  // namespace list_ops
