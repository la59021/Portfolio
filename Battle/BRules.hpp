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
        bool followsRules();
        bool wasThereAWinner();
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
        int index;
        char rowChar, colChar;
        bool won = false;
        bool inputIsInRange();
        bool spaceIsOpen();
        string checkForWin(bool checkingX);
        void changeToIndex();
};