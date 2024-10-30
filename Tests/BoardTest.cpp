#include "../Common/Board.hpp"
using namespace std;

int main() {
    Board board;
    board.set_space_status(1, 'X');
    board.set_space_status(2, 'O');
    board.set_space_status(3, 'X');
    board.set_space_status(4, 'O');
    board.set_space_status(5, 'X');
    board.set_space_status(6, 'O');
    board.set_space_status(7, 'X');
    board.set_space_status(8, 'O');
    board.set_space_status(9, 'X');
    board.print();
    return 0;
}