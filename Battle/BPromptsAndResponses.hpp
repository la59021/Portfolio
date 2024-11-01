#pragma once
#include "BBoard.hpp"
#include <iostream>
#include <string>
using namespace std;

class BPrompts {
    public:
        BPrompts();
        void askToPlayAgain();
};

class BResponses {
    public:
        BResponses(BBoard *board);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        BBoard *board;
};