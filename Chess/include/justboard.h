#pragma once
#include "Position.h"
#include "piece.h"
#include <array>
#include <memory>

class JustBoard {
private:
    std::array<std::shared_ptr<Piece>, SIZE * SIZE> board;

public:
    bool operator==(const JustBoard& other) const;
    JustBoard(const std::array<std::shared_ptr<Piece>, SIZE * SIZE>& other);
    JustBoard(const JustBoard& other);
};
