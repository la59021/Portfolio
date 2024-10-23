#include "Game.hpp"
using namespace std;

Game::Game() {
    isXsTurn = true;
}

void Game::start() {
    Start:
        
}

void Game::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}




