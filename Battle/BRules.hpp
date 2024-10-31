#pragma once
#include "BBoard.hpp"
#include "BPromptsAndResponses.hpp"
#include "BBoardPrinter.hpp"
#include "Classes/Player.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"

class BRules {
    public:
        BRules(BBoard *board);
        void addPlayers(Player *player1, Player *player2);
        bool followsRules(const char rowChar, const char colChar);
        int gameInProgress();
        void player1Turn();
        void player2Turn();
        bool checkForTie();
    private:
        BBoard *board;
        BPrompts prompts;
        BResponses responses = BResponses(board);
        BBoardPrinter printer = BBoardPrinter(board);
        Player *player1;
        Player *player2;
        bool won = false;
        bool checkForWin();
        int changeToIndex(const char rowChar, const char colChar);
        void player1Move();
        void player2Move();
};