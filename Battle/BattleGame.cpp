#include "BattleGame.hpp"
using namespace std;

BattleGame::BattleGame() {
    isXsTurn = true;
}

void BattleGame::startGame() {
        for (int i = 0; i < 9; i++) {
            if (!rules.wasThereAWinner()) {
                if (isXsTurn) {
                    takeTurn();
                    isXsTurn = false;
                }
                else {
                    takeTurn();
                    isXsTurn = true;
                }
            }
            rules.checkForTie();
        }
}

void BattleGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}