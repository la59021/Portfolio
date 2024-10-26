#ifndef NORMALBOARD_HPP
#define NORMALBOARD_HPP
#include "NormalSpace.hpp"
#include <array>
class NormalBoard {
    public:
        NormalBoard();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
        int getLength();
    private:
        NormalSpace currentBoard[9] = {NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace(), NormalSpace()};
        int length;
};
#endif