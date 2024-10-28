#pragma once
#include "NormalGame.hpp"
using namespace std;
class NormalLoop {
    public:
        void start() {
            NormalGame newGame;
            newGame.start();
        }
};