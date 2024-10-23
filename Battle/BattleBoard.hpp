#include <array>
#include "BattleSpace.hpp"

class BattleBoard {
    public:
        BattleBoard();
        int getSpaceStatus(int index);
        void setSpaceStatus(int index, int newState);
        int getLength();
    private:
        BattleSpace currentBoard[9] = {BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace()};
        int length;
};
