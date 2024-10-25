#include "NormalBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class NormalPrompts {
    public:
        NormalPrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();

    private:

};

class NormalResponses {
    public:
        NormalResponses();
        void printBoard(NormalBoard newBoard);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        NormalBoard board;
        string statusToMark(int index);
};
