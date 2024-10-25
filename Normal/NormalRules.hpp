#include "NormalPromptsAndResponses.hpp"

class NormalRules {
    public:
        NormalRules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();

    private:
        NormalPrompts prompts;
        NormalResponses responses;
        NormalBoard board;
        int index;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};
