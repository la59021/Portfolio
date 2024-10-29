#include "BGame.hpp"
using namespace std;

BGame::BGame() {
    isXsTurn = true;
}

void BGame::startGame() {
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

void BGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}