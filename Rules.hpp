#include "PromptsAndResponses.hpp"

class Rules {
    public:
        Rules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();
        bool playAgain();
        int getLastWinner();

    private:
        Prompts prompts;
        Responses responses;
        Board board;
        int index, winner;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};
