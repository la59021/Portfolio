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
        void askToPlayAgain();

    private:

};

class Responses {
    public:
        Responses();
        void printBoard(Board board);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();
    private:
        string statusToMark(int index);
        Board board;
};
#endif
