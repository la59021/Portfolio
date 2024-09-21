#include "Game.hpp"
using namespace std;

Game::Game() {
    isXsTurn = true;
}

void Game::startGame() {
    Start:
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
    if (rules.playAgain()) {
        if (rules.getLastWinner() == 2) {
            isXsTurn = true;
        }
        else {
            isXsTurn = false;
        }
        goto Start;
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




