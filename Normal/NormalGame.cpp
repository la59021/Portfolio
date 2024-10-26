#include "NormalGame.hpp"
using namespace std;

void NormalGame::start() {
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

void NormalGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}




