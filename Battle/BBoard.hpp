#pragma once
#include <array>
#include "BSpace.hpp"

class BBoard {
    public:
        BBoard();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
        int getLength();
    private:
        BSpace currentBoard[9] = {BSpace(), BSpace(), BSpace(), BSpace(), BSpace(), BSpace(), BSpace(), BSpace(), BSpace()};
        int length;
};