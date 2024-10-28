#pragma once
#include "../Common/Board.hpp"
#include <iostream>
#include <string>
using namespace std;
class NormalPrompts {
    public:
        NormalPrompts();
        void askForXSpace();
        void askForOSpace();
        void askToPlayAgain();
};