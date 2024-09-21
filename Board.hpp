#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include "Space.hpp"

class Board {
    public:
        Board();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);

    private:
        Space currentBoard[9] = {Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space()};
};
#endif
