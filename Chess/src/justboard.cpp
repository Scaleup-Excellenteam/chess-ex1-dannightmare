#include "justboard.h"
#include <array>
#include <memory>

JustBoard::JustBoard(
    const std::array<std::shared_ptr<Piece>, SIZE * SIZE> &other)
    : board(other)
{
}

JustBoard::JustBoard(const JustBoard &other) : board(other.board) {}

bool JustBoard::operator==(const JustBoard &other) const
{
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (board[i] != other.board[i]) {
            return false;
        }
    }
    return true;
}
