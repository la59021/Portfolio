#include "NGame.hpp"
#include <iostream>
using namespace std;

NGame::NGame() {
    isXsTurn = true;
}

void NGame::startGame() {
    cout << "At any point when asked for an input use \"q\" or \"Q\" to quit.\n";
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

void NGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}