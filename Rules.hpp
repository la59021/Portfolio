#include "PromptsAndResponses.hpp"
#include "Board.hpp"

class Rules {
    public:
        Rules();
        bool followsRules();
        bool wasThereAWinner();
        void takeXTurn();
        void takeOTurn();

    private:
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        bool checkForTie();
        void changeToIndex();
        Prompts prompts;
        Responses responses;
        Board board;
        int index;
        char rowChar, colChar;
        bool won = false;

};
