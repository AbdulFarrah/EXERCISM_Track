#include "dnd_character.h"
namespace dnd_character {
// TODO: add your solution here
int modifier(int constitution)
{
     return static_cast<int>(std::floor((constitution - 10) / 2.0));
}
int ability()
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(1, 6);
    array<int, 4> rolls;
    for (int &x : rolls)
        x = dist(gen);
    sort(rolls.begin(), rolls.end());
    return rolls[1] + rolls[2] + rolls[3];
}
Character::Character()
{
    strength = ability();
    dexterity = ability();
    constitution = ability();
    intelligence = ability();
    wisdom = ability();
    charisma = ability();
    hitpoints = 10 + modifier(constitution);
}
}  // namespace dnd_character
