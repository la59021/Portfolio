#include "Space.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

Space::Space() {

}

int Space::getStatus() {
    return state;
}

void Space::setStatus(int newState) {
    state = newState;
}
