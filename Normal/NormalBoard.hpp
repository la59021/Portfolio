#include <array>
#include "NormalSpace.hpp"

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
