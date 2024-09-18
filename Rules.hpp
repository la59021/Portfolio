#include "PromptsAndResponses.hpp"
#include "Board.hpp"

class Rules {
    public:
        Rules();
        bool followsRules(int typeOfCheck, bool lookingAtX, int row, int col); // 0 is in range and occupancy, 1 is win, 2 is tie

        void takeXTurn();
        void takeOTurn();

    private:
        bool inputIsInRange(int row, int col);
        bool spaceIsOpen(int row, int col);
        bool checkForWin(bool checkingX);
        bool checkForTie();
        Prompts prompts;
        Responses responses;
        Board board;
        bool won = false;

};
