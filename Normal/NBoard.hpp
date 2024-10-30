#pragma once
#include <array>
#include "NSpace.hpp"

class NBoard {
    public:
        NBoard();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
        int getLength();
    private:
        NSpace currentBoard[9] = {NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace()};
        int length;
};