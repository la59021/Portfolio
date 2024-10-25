#include "BattleSpace.hpp"

// state 0 = empty
// state 1 = marked X
// state 2 = marked O

BattleSpace::BattleSpace() {

}

int BattleSpace::getStatus() {
    return state;
}

void BattleSpace::setStatus(int newState) {
    state = newState;
}
