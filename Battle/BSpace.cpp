#include "BSpace.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

BSpace::BSpace() {
    state = 0;
}

int BSpace::getStatus() const {
    return state;
}

void BSpace::setStatus(int newState) {
    state = newState;
}