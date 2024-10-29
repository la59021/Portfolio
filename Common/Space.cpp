#include "Space.hpp"

// State Explinations 
// state = 0 => empty space
// state = 1 => marked by player 1
// state = 2 => marked by player 2

Space::Space() {
    state = ' ';
}

char Space::getStatus() {
    return state;
}

void Space::setStatus(char newState) {
    state = newState;
}
