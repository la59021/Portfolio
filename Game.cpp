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
        if (i % 2 == 0) {
            this -> takeTurn(true);
        }
        else {
            this -> takeTurn(false);
        }

    }
    if (x == 9) {

    }

}



