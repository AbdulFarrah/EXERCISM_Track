#pragma once
#include <stdexcept>
using namespace std;
namespace perfect_numbers {
enum class classification{perfect,abundant,deficient};
classification classify(int);
}  // namespace perfect_numbers
