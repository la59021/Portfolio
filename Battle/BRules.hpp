#pragma once
#include "BPromptsAndResponses.hpp"

class BRules {
    public:
        BRules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();

    private:
        BPrompts prompts;
        BResponses responses = Responses(&board);
        BBoard board;
        int index;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};