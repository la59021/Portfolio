#pragma once
#include "Space.hpp"
#include "BoardPrinter.hpp"
#include <array>
class Board {
    public:
        Board();
        int get_space_status(int index);
        void set_space_status(int index, int newState);
        int get_length();
        bool unfilled_spaces();
        int change_to_index(char rowChar, char colChar);
        bool valid_inputs(char rowChar, char colChar);
        bool empty_space(int index);
    private:
        Space currentBoard[9] = {Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space(), Space()};
        int length;
};