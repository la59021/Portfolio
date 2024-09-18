#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include "Space.hpp"

class Board {
    public:
        Board();
        int getSpaceStatus(int row, int col);
        void setSpaceStatus(int row, int col, int newState);

    private:
        Space currentBoard[3][3] = {{Space(),Space(),Space()},
                                    {Space(),Space(),Space()},
                                    {Space(),Space(),Space()}};

};
#endif
