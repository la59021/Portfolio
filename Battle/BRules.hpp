#pragma once
#include "BBoard.hpp"
#include "BBoardPrinter.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"
#include "Classes/Player.hpp"
using namespace std;

class BRules {
    public:
        BRules(BBoard *board);
        void addPlayers(Player *player1, Player *player2);
        bool checkForTie();
        bool followsRules(const char rowChar, const char colChar);
        int gameInProgress();
        void player1Turn();
        void player2Turn();
    private:
        int changeToIndex(const char rowChar, const char colChar);
        bool checkForWin();
        void player1Move();
        void player2Move();
        string winningCombo();
        BBoard *board;
        Player *player1;
        Player *player2;
        BBoardPrinter printer = BBoardPrinter(board);
        bool won = false;
};