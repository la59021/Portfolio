#pragma once
#include "NPromptsAndResponses.hpp"

class NRules {
    public:
        NRules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();

    private:
        NPrompts prompts;
        NResponses responses = NResponses(&board);
        NBoard board;
        int index;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};