#pragma once
#include "Board.hpp"
#include <iostream>
#include <string>
using namespace std;

class Prompts {
    public:
        Prompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();

    private:

};

class Responses {
    public:
        Responses(Board *board);
        void printBoard();
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        Board *board;
        string statusToMark(int index);
};