#include "BattleSpace.hpp"
#include <array>

class BattleBoard {
    public:
        BattleBoard();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
        int getLength();
    private:
        Space currentBoard[9] = {Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space()};
        int length;
};
