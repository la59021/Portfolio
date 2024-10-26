#ifndef NORMALRESPONSES_HPP
#define NORMALRESPONSES_HPP
#include "NormalBoard.hpp"
#include <iostream>
#include <string>
using namespace std;
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
#endif