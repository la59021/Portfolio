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
        Responses();
        void printBoard(Board newBoard);
        void isInvalidSpace();
        void winnerIsX();
        void winnerIsO();
        void gameWasTie();

    private:
        Board board;
        string statusToMark(int index);
};
