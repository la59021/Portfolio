#include "BattleBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class BattlePrompts {
    public:
        BattlePrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();

    private:

};

class BattleResponses {
    public:
        BattleResponses();
        void printBoard(BattleBoard newBoard);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        BattleBoard board;
        string statusToMark(int index);
};
