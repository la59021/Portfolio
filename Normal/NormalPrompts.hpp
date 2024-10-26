#ifndef NORMALPROMPTS_HPP
#define NORMALPROMPTS_HPP
#include "NormalBoard.hpp"
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
#endif