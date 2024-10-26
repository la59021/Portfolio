#ifndef NORMALLOOP_HPP
#define NORMALLOOP_HPP
#include "NormalGame.hpp"
using namespace std;
class NormalLoop {
    public:
        void start() {
            NormalGame newGame;
            newGame.start();
        }
};
#endif