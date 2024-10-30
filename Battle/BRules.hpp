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
        bool followsRules(const char rowChar, const char colChar);
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
        bool won = false;
        bool inputIsInRange(const char rowChar, const char colChar);
        bool spaceIsOpen(const int index);
        string checkForWin();
        int changeToIndex(const char rowChar, const char colChar);
        void makeXMove();
        void makeOMove();
};