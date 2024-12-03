#include "NRules.hpp"
#include <iostream>
#include "NGame.hpp"
using namespace std;

NGame::NGame() {
    isXsTurn = true;
}

int NGame::startGame() {
    cout << "At any point when asked for an input use \"q\" or \"Q\" to quit.\n";
    for (int i = 0; i < 9; i++) {
        if (rules.wasThereAWinner() == 0) {
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
    return rules.wasThereAWinner(); 
}

void NGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}