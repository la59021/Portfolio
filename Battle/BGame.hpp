#pragma once
#include "BBoard.hpp"
#include "BRules.hpp"
#include "Classes/Player.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"
using namespace std;

class BGame {
    public:
        BGame();
        void startGame();
    private:
        void createPlayers();
        Player *player1;
        Player *player2;
        BBoard board;
        BRules *rules;
};