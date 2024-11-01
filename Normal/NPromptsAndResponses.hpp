#pragma once
#include "NBoard.hpp"
#include <string>
using namespace std;

class NPrompts {
    public:
        NPrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();
};

class NResponses {
    public:
        NResponses(NBoard *board);
        void gameWasTie();
        void isInvalidSpace();
        void printBoard();
        void winnerIsX();
        void winnerIsO();
    private:
        string statusToMark(int index);
        NBoard *board;
};