#pragma once
#include <cmath>
#include <random>
#include <array>
#include <algorithm>
using namespace std;
namespace dnd_character {
// TODO: add your solution here
int modifier(int constitution);
int ability();
class Character{
    public:
    Character();
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints;
};
}  // namespace dnd_character
