#include "Space.hpp"

// State Explinations 
// state = 0 => empty space
// state = 1 => marked by player 1
// state = 2 => marked by player 2

Space::Space() {
    state = 0;
}

int Space::getStatus() {
    return state;
}

void Space::setStatus(int newState) {
    state = newState;
}
