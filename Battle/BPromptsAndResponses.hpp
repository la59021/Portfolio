#pragma once
#include "BBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class BPrompts {
    public:
        BPrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();
};

class BResponses {
    public:
        BResponses(BBoard *board);
        void printBoard();
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        BBoard *board;
        string statusToMark(int index);
};