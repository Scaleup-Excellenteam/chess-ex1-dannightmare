// Chess
#include "Chess.h"
#include "Position.h"
#include "board.h"
#include <stdexcept>

enum AI {
    NONE = 0,
    BLACK,
    WHITE,
};

void parseInput(const string &res, Position &pos1, Position &pos2);
void parseMove(const Position &pos1, const Position &pos2, string &res);
bool isTurnAI(const bool turn, const int AI);

#define DEPTH 2

int main()
{
    // Two rooks
    // string board =
    //     "#K##########r######r############################################";
    // Standard game
    string board =
        "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr";
    // string board =
    // "Q#####################B########R###########r######b#####q#######";
    // string board =
    // "##########K###############################R#############r#r#####";
    // string board =
    // "##########K#######p#####P#################R#############r#r#####";
    Board b(board);
    Chess a(board);
    int codeResponse = 0;
    string res       = "";
    int AI           = -1;
    Position pos1, pos2;

    std::cout
        << "Please choose computer AI:\n\n\t0 - None\n\t1 - Black\n\t2 - White"
        << std::endl;
    std::cin >> AI;

    a.preGetInput();
    try {
        auto pq  = b.getBestMoves(DEPTH, b.get_turn_color());
        Move mov = pq.poll();
        pos1 = mov.src, pos2 = mov.dst;
        parseMove(pos1, pos2, res);
    } catch (runtime_error re) {
    }
    if (!isTurnAI(a.getTurn(), AI)) {
        std::cout << "recommended move: " << res << std::endl;
        res = a.getInput();
    } else {
        a.setInput(res);
    }
    while (res != "exit") {
        /*
        codeResponse value :
        Illegal movements :
        11 - there is not piece at the source
        12 - the piece in the source is piece of your opponent
        13 - there one of your pieces at the destination
        21 - illegal movement of that piece
        31 - this movement will cause you checkmate

        legal movements :
        41 - the last movement was legal and cause check
        42 - the last movement was legal, next turn
        */

        /**/
        { // put your code here instead that code
            Position pos1, pos2;

            parseInput(res, pos1, pos2);

            a.setCodeResponse(b.move(pos1, pos2));
        }
        /**/

        a.preGetInput();
        try {
            auto pq  = b.getBestMoves(DEPTH, b.get_turn_color());
            Move mov = pq.poll();
            pos1 = mov.src, pos2 = mov.dst;
            parseMove(pos1, pos2, res);
        } catch (runtime_error re) {
        }
        if (!isTurnAI(a.getTurn(), AI)) {
            std::cout << "recommended move: " << res << std::endl;
            res = a.getInput();
        } else {
            a.setInput(res);
        }
    }

    cout << endl << "Exiting " << endl;
    return 0;
}

void parseInput(const string &res, Position &pos1, Position &pos2)
{
    pos1.y = tolower(res[0]) - 'a';
    pos1.x = res[1] - '1';
    pos2.y = tolower(res[2]) - 'a';
    pos2.x = res[3] - '1';
}

void parseMove(const Position &pos1, const Position &pos2, string &res)
{
    res = pos1.y + 'a';
    res += pos1.x + '1';
    res += pos2.y + 'a';
    res += pos2.x + '1';
}

bool isTurnAI(const bool turn, const int AI)
{
    if (AI == NONE) {
        return false;
    }
    return turn == AI - 1;
}
