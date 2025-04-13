#include "piece.h"
#include <array>
#include <memory>

using namespace std;
class Board {
private:
    static const int SIZE = 8;
    array<unique_ptr<Piece>, SIZE*SIZE> _board;

public:
    Board();
    Board(string init);
    ~Board();

    bool isCheck();
};
