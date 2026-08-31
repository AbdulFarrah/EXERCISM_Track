#pragma once
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;
namespace phone_number {
// TODO: add your solution here
class phone_number
{
    public:
    phone_number(string);
    string number();
    string num;
};
}  // namespace phone_number
