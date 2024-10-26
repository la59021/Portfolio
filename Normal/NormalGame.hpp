#ifndef NORMALGAME_HPP
#define NORMALGAME_HPP
#include "NormalRules.hpp"
using namespace std;
class NormalGame {
    public:
        void start();
    private:
        NormalRules rules;
        bool isXsTurn=true;
        void takeTurn();
};
#endif