#include <array>
#include <iostream>
using namespace std;

class GameBoard {
    public:
        explicit GameBoard();
        bool pickedSpaceUnoccupied(int* cords);
        void addPiece(int* cords, string marker);
        bool checkForWin();
        void printBoard();

    private:
        string board[3][3] = {{"", "", ""}, {"", "", ""}, {"", "", ""}};
};

