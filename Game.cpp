#include "Game.hpp"
using namespace std;

Game::Game() {
    isXsTurn = true;
}

void Game::startGame() {
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

void Game::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}




