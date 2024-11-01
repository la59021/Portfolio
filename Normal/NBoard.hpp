#pragma once
#include "NSpace.hpp"
using namespace std;

class NBoard {
    public:
        NBoard();
        int getLength();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
    private:
        NSpace currentBoard[9] = {NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace(), NSpace()};
        int length;
};