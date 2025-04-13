#include "board.h"
#include <cassert>
#include <cctype>

Board::Board() {}

Board::Board(string init) {
    assert(init.length() == SIZE * SIZE);
    bool is_white;
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (init[i] == '#')
            continue;

        if (islower(init[i]))
            is_white = false;
        else
            is_white = true;

        switch (tolower(init[i])) {
        case 'r':
            _board[i] = make_unique<Rook>(is_white);
//        case 'n':
//            _board[i] = make_unique<Knight>(is_white);
//        case 'b':
//            _board[i] = make_unique<Bishop>(is_white);
//        case 'q':
//            _board[i] = make_unique<Queen>(is_white);
        case 'k':
            _board[i] = make_unique<King>(is_white);
//        case 'p':
//            _board[i] = make_unique<Pawn>(is_white);
        }
    }
}

Board::~Board() {}
