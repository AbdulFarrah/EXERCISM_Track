#pragma once
#include <utility>
#include <stdexcept>
#include <cstdlib>
namespace queen_attack {
class chess_board
{
private:
    std::pair<int, int> _white;
    std::pair<int, int> _black;
public:
    chess_board(const std::pair<int, int>& white,
                const std::pair<int, int>& black);
    const std::pair<int, int>& white() const;
    const std::pair<int, int>& black() const;
    bool can_attack() const;
};
}