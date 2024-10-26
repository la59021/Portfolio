#ifndef BATTLEBOARD_HPP
#define BATTLEBOARD_HPP
#include "BattleSpace.hpp"
#include <array>
class BattleBoard {
    public:
        BattleBoard();
        int get_space_status(int index);
        void set_space_status(int index, int newState);
        int get_length();
        bool unfilled_spaces();
        int change_to_index(char rowChar, char colChar);
        bool valid_inputs(char rowChar, char colChar);
        bool empty_space(int index);
    private:
        BattleSpace currentBoard[9] = {BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace(), BattleSpace()};
        int length;
};
#endif