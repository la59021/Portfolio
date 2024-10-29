#include "BSpace.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

BSpace::BSpace() {

}

int BSpace::getStatus() {
    return state;
}

void BSpace::setStatus(int newState) {
    state = newState;
}