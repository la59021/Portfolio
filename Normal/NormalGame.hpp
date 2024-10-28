#pragma once
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