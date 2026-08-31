#pragma once
#include <array>
#include <string>
#include <cstdlib>
#include <stdexcept>
namespace zebra_puzzle {
constexpr int HOUSE_COUNT = 5;
constexpr int UNASSIGNED = 0;
enum Colour {
    RED,
    GREEN,
    IVORY,
    YELLOW,
    BLUE
};
enum Nationality {
    ENGLISHMAN,
    SPANIARD,
    UKRAINIAN,
    NORWEGIAN,
    JAPANESE
};
enum Drink {
    COFFEE,
    TEA,
    MILK,
    ORANGE_JUICE,
    WATER
};
enum Hobby {
    DANCING,
    PAINTING,
    READING,
    FOOTBALL,
    CHESS
};
enum Pet {
    DOG,
    SNAILS,
    FOX,
    HORSE,
    ZEBRA
};
using Positions = std::array<int, HOUSE_COUNT>;
struct Solution1 {
    Positions colours;
    Positions nationalities;
    Positions drinks;
    Positions hobbies;
    Positions pets;
};
struct Solution{
    std::string drinksWater;
    std::string ownsZebra;
};  
Solution solve();
} // namespace zebra_puzzle