#pragma once
#include "NBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class NPrompts {
    public:
        NPrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();

    private:

};

class NResponses {
    public:
        NResponses(NBoard *board);
        void printBoard();
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        NBoard *board;
        string statusToMark(int index);
};