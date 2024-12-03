#pragma once
#include "NBoard.hpp"
#include "NPromptsAndResponses.hpp"
#include <string>
using namespace std;

class NRules {
    public:
        NRules();
        bool checkForTie();
        bool followsRules();
        int wasThereAWinner();
        void takeXTurn();
        void takeOTurn();

    private:
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
        int winner;
        char colChar, rowChar;
        int index;
        NBoard board;
        NPrompts prompts;
        NResponses responses = NResponses(&board);
        
};