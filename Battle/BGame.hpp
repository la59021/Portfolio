#pragma once
#include "BBoard.hpp"
#include "BRules.hpp"
#include "Classes/Player.hpp"
using namespace std;

class BGame {
    public:
        BGame();
        int startGame();
    private:
        void createPlayers();
        BBoard board;
        Player *player1;
        Player *player2;
        BRules *rules;
};