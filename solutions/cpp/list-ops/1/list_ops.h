#pragma once
#include <vector>
#include <functional>
using namespace std;
namespace list_ops {
void append(vector<int>&, const vector<int>&);
const vector<int> concat(const vector<vector<int>>&);
const vector<vector<int>> concat(const vector<vector<vector<int>>>&);
const vector<int> filter(const vector<int>&,const function<bool(int)>&);
size_t length(const vector<int>&);
const vector<int> map(const vector<int>&,const function<int(int)>&);
int foldl(const vector<int>&,int,const function<int(int,int)>&);
double foldl(const vector<double>&,double,const function<double(double,double)>&);
int foldr(const vector<int>&,int,const function<int(int,int)>&);
double foldr(const vector<double>&,double,const function<double(double,double)>&);
const vector<int> reverse(const vector<int>&);
const vector<vector<int>> reverse(const vector<vector<int>>&);
}  // namespace list_ops