#pragma once
#include "../Common/Board.hpp"
#include <iostream>
#include <string>
using namespace std;
class NormalResponses {
    public:
        NormalResponses();
        void printBoard(Board newBoard);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();
    private:
        Board board;
        string statusToMark(int index);
};