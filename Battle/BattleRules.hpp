#include "PromptsAndResponses.hpp"

class BattleRules {
    public:
        BattleRules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();

    private:
        BattlePrompts prompts;
        BattleResponses responses;
        BattleBoard board;
        int index;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};
