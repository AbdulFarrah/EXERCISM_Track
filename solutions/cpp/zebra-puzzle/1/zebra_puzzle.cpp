#include "zebra_puzzle.h"
namespace zebra_puzzle {
namespace {
struct State {
    Positions colours{};
    Positions nationalities{};
    Positions drinks{};
    Positions hobbies{};
    Positions pets{};
};
bool used(const Positions& positions, int house)
{
    for (int position : positions)
        if (position == house)
            return true;
    return false;
}
bool next_to(int first, int second)
{
    return std::abs(first - second) == 1;
}
void save_Solution1(
    const State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
    Solution1 = {
        state.colours,
        state.nationalities,
        state.drinks,
        state.hobbies,
        state.pets
    };
    ++Solution1_count;
}
void assign_pets(
    State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
       state.pets[DOG] =
       state.nationalities[SPANIARD];
    state.pets[SNAILS] =
        state.hobbies[DANCING];
    if (state.pets[DOG] == state.pets[SNAILS]) {
        state.pets[DOG] = UNASSIGNED;
        state.pets[SNAILS] = UNASSIGNED;
        return;
    }
    for (int fox = 1; fox <= HOUSE_COUNT; ++fox) {
        if (!next_to(state.hobbies[READING], fox))
            continue;
        if (used(state.pets, fox))
            continue;
        state.pets[FOX] = fox;
        for (int horse = 1;
             horse <= HOUSE_COUNT;
             ++horse) {
            if (!next_to(
                    state.hobbies[PAINTING],
                    horse))
                continue;
            if (used(state.pets, horse))
                continue;
            state.pets[HORSE] = horse;
            for (int zebra = 1;
                 zebra <= HOUSE_COUNT;
                 ++zebra) {
                if (used(state.pets, zebra))
                    continue;
                state.pets[ZEBRA] = zebra;
                save_Solution1(
                    state,
                    Solution1,
                    Solution1_count
                );
                state.pets[ZEBRA] = UNASSIGNED;
            }
            state.pets[HORSE] = UNASSIGNED;
        }
        state.pets[FOX] = UNASSIGNED;
    }
    state.pets[DOG] = UNASSIGNED;
    state.pets[SNAILS] = UNASSIGNED;
}
void assign_hobbies(
    State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
    state.hobbies[PAINTING] =
        state.colours[YELLOW];
    state.hobbies[FOOTBALL] =
        state.drinks[ORANGE_JUICE];
    state.hobbies[CHESS] =
        state.nationalities[JAPANESE];
    if (state.hobbies[PAINTING] ==
            state.hobbies[FOOTBALL] ||
        state.hobbies[PAINTING] ==
            state.hobbies[CHESS] ||
        state.hobbies[FOOTBALL] ==
            state.hobbies[CHESS]) {
        state.hobbies[PAINTING] = UNASSIGNED;
        state.hobbies[FOOTBALL] = UNASSIGNED;
        state.hobbies[CHESS] = UNASSIGNED;
        return;
    }
    for (int dancing = 1;
         dancing <= HOUSE_COUNT;
         ++dancing) {
        if (used(state.hobbies, dancing))
            continue;
        state.hobbies[DANCING] = dancing;
        for (int reading = 1;
             reading <= HOUSE_COUNT;
             ++reading) {
            if (used(state.hobbies, reading))
                continue;
            state.hobbies[READING] = reading;
            assign_pets(
                state,
                Solution1,
                Solution1_count
            );
            state.hobbies[READING] = UNASSIGNED;
        }
        state.hobbies[DANCING] = UNASSIGNED;
    }
    state.hobbies[PAINTING] = UNASSIGNED;
    state.hobbies[FOOTBALL] = UNASSIGNED;
    state.hobbies[CHESS] = UNASSIGNED;
}
void assign_drinks(
    State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
    state.drinks[COFFEE] =
        state.colours[GREEN];
    state.drinks[TEA] =
        state.nationalities[UKRAINIAN];
    state.drinks[MILK] = 3;
    if (state.drinks[COFFEE] ==
            state.drinks[TEA] ||
        state.drinks[COFFEE] ==
            state.drinks[MILK] ||
        state.drinks[TEA] ==
            state.drinks[MILK]) {
        state.drinks[COFFEE] = UNASSIGNED;
        state.drinks[TEA] = UNASSIGNED;
        state.drinks[MILK] = UNASSIGNED;
        return;
    }
    for (int orange = 1;
         orange <= HOUSE_COUNT;
         ++orange) {
        if (used(state.drinks, orange))
            continue;
        state.drinks[ORANGE_JUICE] = orange;
        for (int water = 1;
             water <= HOUSE_COUNT;
             ++water) {
            if (used(state.drinks, water))
                continue;
            state.drinks[WATER] = water;
            assign_hobbies(
                state,
                Solution1,
                Solution1_count
            );
            state.drinks[WATER] = UNASSIGNED;
        }
        state.drinks[ORANGE_JUICE] = UNASSIGNED;
    }
    state.drinks[COFFEE] = UNASSIGNED;
    state.drinks[TEA] = UNASSIGNED;
    state.drinks[MILK] = UNASSIGNED;
}
void assign_nationalities(
    State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
    state.nationalities[ENGLISHMAN] =
        state.colours[RED];
    if (state.nationalities[ENGLISHMAN] ==
        state.nationalities[NORWEGIAN]) {
        state.nationalities[ENGLISHMAN] = UNASSIGNED;
        return;
    }
    for (int spaniard = 1;
         spaniard <= HOUSE_COUNT;
         ++spaniard) {
        if (used(state.nationalities, spaniard))
            continue;
        state.nationalities[SPANIARD] = spaniard;
        for (int ukrainian = 1;
             ukrainian <= HOUSE_COUNT;
             ++ukrainian) {
            if (used(state.nationalities, ukrainian))
                continue;
            state.nationalities[UKRAINIAN] = ukrainian;
            for (int japanese = 1;
                 japanese <= HOUSE_COUNT;
                 ++japanese) {
                if (used(state.nationalities, japanese))
                    continue;
                state.nationalities[JAPANESE] = japanese;
                assign_drinks(
                    state,
                    Solution1,
                    Solution1_count
                );
                state.nationalities[JAPANESE] = UNASSIGNED;
            }
            state.nationalities[UKRAINIAN] = UNASSIGNED;
        }
        state.nationalities[SPANIARD] = UNASSIGNED;
    }
    state.nationalities[ENGLISHMAN] = UNASSIGNED;
}
void assign_colours(
    State& state,
    Solution1& Solution1,
    int& Solution1_count)
{
    for (int ivory = 1;
         ivory < HOUSE_COUNT;
         ++ivory) {
        int green = ivory + 1;
        if (used(state.colours, ivory) ||
            used(state.colours, green))
            continue;
        state.colours[IVORY] = ivory;
        state.colours[GREEN] = green;
        for (int red = 1;
             red <= HOUSE_COUNT;
             ++red) {
            if (used(state.colours, red))
                continue;
            state.colours[RED] = red;
            for (int yellow = 1;
                 yellow <= HOUSE_COUNT;
                 ++yellow) {
                if (used(state.colours, yellow))
                    continue;
                state.colours[YELLOW] = yellow;
                assign_nationalities(
                    state,
                    Solution1,
                    Solution1_count
                );
                state.colours[YELLOW] = UNASSIGNED;
            }
            state.colours[RED] = UNASSIGNED;
        }
        state.colours[IVORY] = UNASSIGNED;
        state.colours[GREEN] = UNASSIGNED;
    }
}
}
Solution solve()
{
    State state{};
   state.nationalities[NORWEGIAN] = 1;
    state.colours[BLUE] = 2;
    Solution1 solution1{};
    int Solution1_count = 0;
    assign_colours(
        state,
        solution1,
        Solution1_count
    );
    if (Solution1_count != 1)
        throw std::runtime_error(
            "Puzzle does not have exactly one Solution1"
        );
Solution result;
const std::string names[] = {
    "Englishman",
    "Spaniard",
    "Ukrainian",
    "Norwegian",
    "Japanese"
};
for (int i = 0; i < HOUSE_COUNT; ++i) {
    if (solution1.nationalities[i] == solution1.drinks[WATER])
        result.drinksWater = names[i];
    if (solution1.nationalities[i] == solution1.pets[ZEBRA])
        result.ownsZebra = names[i];
}
return result;
}
} // namespace zebra_puzzle