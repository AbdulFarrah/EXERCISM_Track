#pragma once
#include <string>
#include <array>
#include <stdexcept>
using namespace std;
namespace kindergarten_garden {
// TODO: add your solution here
enum class Plants{clover,grass,violets,radishes};
array<Plants,4> plants(const string&,const string&);
Plants to_plant(char);
}  // namespace kindergarten_garden
