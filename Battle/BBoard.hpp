#pragma once
#include "BSpace.hpp"
using namespace std;

class BBoard {
    public:
        BBoard();
        int getLength();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
    private:
        BSpace currentBoard[9];
};