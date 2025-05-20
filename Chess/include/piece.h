#pragma once
#include "Move.h"
#include "Position.h"
#include <vector>

// This is a Piece,
// the base class for all pieces
class Piece
{
private:
    bool _is_white;

public:
    virtual bool isValidMove(Position src, Position dst) = 0;
    virtual std::vector<Move> getAllValidMoves(Position src) = 0;

    bool Color() { return _is_white; }
    Piece(bool is_white) : _is_white(is_white) {}
    ~Piece() {}

    const int value = -1;
};

class King : public virtual Piece
{
public:
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    King(bool is_white = true) : Piece(is_white) {}
    ~King() {}

    const int value = 1000;
};

class Queen : public Piece
{
public:
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    Queen(bool is_white = true) : Piece(is_white) {}

    const int value = 9;
};

class Rook : public virtual Piece
{
public:
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    Rook(bool is_white = true) : Piece(is_white) {}
    ~Rook() {}

    const int value = 5;
};

class Knight : public Piece
{
public:
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    Knight(bool is_white = true) : Piece(is_white) {}

    const int value = 3;
};

class Bishop : public Piece
{
public:
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    Bishop(bool is_white = true) : Piece(is_white) {}

    const int value = 3;
};

class Pawn : public Piece
{
public:
    // only exists because the method is virtual
    bool isValidMove(Position src, Position dst) override;
    std::vector<Move> getAllValidMoves(Position src) override;

    bool isValidMove(Position src, Position dst, bool isAttacking);
    Pawn(bool is_white = true) : Piece(is_white) {}

    const int value = 1;
};
