#pragma once
#include "NormalPrompts.hpp"
#include "NormalResponses.hpp"
using namespace std;
class NormalRules {
    public:
        NormalRules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();
        bool playAgain();
        int getLastWinner();
    private:
        NormalPrompts prompts;
        NormalResponses responses;
        Board board;
        int index, winner;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};