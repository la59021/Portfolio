#pragma once
#include "BRules.hpp"
using namespace std;

class BGame {
    public:
        BGame();
        void startGame();

    private:
        BRules rules;
        bool isXsTurn;
        void takeTurn();
};