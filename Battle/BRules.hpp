#pragma once
#include "BPromptsAndResponses.hpp"
#include "BBoardPrinter.hpp"
#include "Classes/Player.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"

class BRules {
    public:
        BRules();
        void addPlayers(Player *player1, Player *player2);
        bool followsRules(char rowChar, char colChar);
        int gameInProgress();
        void takeXTurn();
        void takeOTurn();
        bool checkForTie();
    private:
        BBoard board;
        BPrompts prompts;
        BResponses responses = BResponses(&board);
        BBoardPrinter printer = BBoardPrinter(&board);
        Player *player1;
        Player *player2;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange(char rowChar, char colChar);
        bool spaceIsOpen(int index);
        string checkForWin();
        int changeToIndex(char rowChar, char colChar);
};