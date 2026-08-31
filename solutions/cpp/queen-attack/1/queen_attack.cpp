#include "queen_attack.h"
namespace queen_attack {
// TODO: add your solution here
chess_board::chess_board(const std::pair<int, int>& white,
                         const std::pair<int, int>& black)
{
    if (white.first < 0 || white.first > 7 ||
        white.second < 0 || white.second > 7 ||
        black.first < 0 || black.first > 7 ||
        black.second < 0 || black.second > 7 ||
        (white.first == black.first && white.second==black.second))
    {
        throw std::domain_error("Invalid position");
    }

    _white = white;
    _black = black;
}
const std::pair<int,int>& chess_board::white() const
{
    return _white;
}
const std::pair<int,int>& chess_board::black() const
{
    return _black;
}
bool chess_board::can_attack() const
{
    return _white.first == _black.first ||
           _white.second == _black.second ||
           std::abs(_white.first - _black.first) ==
           std::abs(_white.second - _black.second);
}
}  // namespace queen_attack
