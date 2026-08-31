#include "kindergarten_garden.h"
namespace kindergarten_garden {
// TODO: add your solution here
array<Plants, 4> plants(const string& garden, const string& name)
{
    int first = (name[0] - 'A') * 2;
    size_t offset = garden.find('\n') + 1;

    return {
        to_plant(garden[first]),
        to_plant(garden[first + 1]),
        to_plant(garden[offset + first]),
        to_plant(garden[offset + first + 1])
    };
}
Plants to_plant(char c)
{
    switch (c)
    {
        case 'G': return Plants::grass;
        case 'C': return Plants::clover;
        case 'R': return Plants::radishes;
        case 'V': return Plants::violets;
    }
    throw invalid_argument("Invalid plant");
}
}  // namespace kindergarten_garden
