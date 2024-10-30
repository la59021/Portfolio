#pragma once
#include "BRules.hpp"
#include "Classes/Player.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"
using namespace std;

class BGame {
    public:
        void startGame();
    private:
        void createPlayers();
        Player *player1;
        Player *player2;
        BRules rules;
};