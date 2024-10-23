#include "Battle/BattleBoard.hpp"
using namespace std;

class BattleLoop {
    public:
        void start() {
            BattleBoard board();
            Start:
                while(board.unfilled_spaces()) {

                }

        
        }

        void Game::takeTurn() {
            if (isXsTurn) {
                rules.takeXTurn();
            }
            else if (!isXsTurn) {
                rules.takeOTurn();
            }
        }
        
};