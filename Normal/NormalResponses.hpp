#include "BattleBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class Responses {
    public:
        Responses();
        void printBoard(Board newBoard);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        Board board;
        string statusToMark(int index);
};
