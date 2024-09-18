#include <iostream>
#include "Game.hpp"
using namespace std;

Game::Game() {
    //ctor
}

void Game::takeTurn(bool isXsTurn) {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}

void Game::startGame() {
    int x = 0;
    for (int i = 0; x < 9; x++) {
        if (!rules.wasThereAWinner()) {
            if (x % 2 == 0) {
                takeTurn(true);
            }
            else {
                takeTurn(false);
            }
        }
    }
}



