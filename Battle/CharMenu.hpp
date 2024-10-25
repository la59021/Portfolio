#include "BattleGame.hpp"
using namespace std;

class CharMenu {
    public:
        CharMenu();
    private:
        char player1mark;
        char player2mark;
        void ask_for_char(int player);
        void input_char(int player);
};