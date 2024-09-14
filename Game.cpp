#include <iostream>
#include "Prompts.hpp"
#include "Game.hpp"
using namespace std;

Game::Game() {
    Prompts printing(false);
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printing.takeTurn(false);
        }
        else {
            printing.takeTurn(true);
        }
    }
}
