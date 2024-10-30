#pragma once
#include "NRules.hpp"
using namespace std;

class NGame {
    public:
        NGame();
        void startGame();

    private:
        NRules rules;
        bool isXsTurn;
        void takeTurn();
};