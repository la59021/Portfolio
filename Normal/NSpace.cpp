#include "NSpace.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

NSpace::NSpace() {
    state = 0;
}

int NSpace::getStatus() {
    return state;
}

void NSpace::setStatus(int newState) {
    state = newState;
}