#pragma once
#include "NRules.hpp"
using namespace std;

class NGame {
    public:
        NGame();
        void startGame();
    private:
        void takeTurn();
        NRules rules;
        bool isXsTurn;
};