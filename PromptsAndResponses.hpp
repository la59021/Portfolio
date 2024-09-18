#ifndef PROMPTSANDRESPONSES_HPP
#define PROMPTSANDRESPONSES_HPP

#include "Board.hpp"
#include <string>
using namespace std;

class Prompts {
    public:
        Prompts();
        void askForXSpace();
        void askForOSpace();

    private:

};

class Responses {
    public:
        Responses();
        void printBoard(Board board);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
    private:
        string statusToMark(int row, int col);
        Board board;
};
#endif
