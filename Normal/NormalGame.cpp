#include "NormalGame.hpp"
using namespace std;

void NormalGame::start() {
    Start:
        
}

void NormalGame::takeTurn() {
    if (isXsTurn) {
        rules.takeXTurn();
    }
    else if (!isXsTurn) {
        rules.takeOTurn();
    }
}




