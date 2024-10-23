#include "BattleRules.hpp"
using namespace std;

class BattleGame {
    public:
        BattleGame();
        void startGame();

    private:
        BattleRules rules;
        bool isXsTurn;
        void takeTurn();
};
