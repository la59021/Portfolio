#include "NormalSpace.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

NormalSpace::NormalSpace() {

}

int NormalSpace::getStatus() {
    return state;
}

void NormalSpace::setStatus(int newState) {
    state = newState;
}
