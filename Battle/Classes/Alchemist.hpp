#include "../BattleBoard.hpp"
#include "../BattleRules.hpp"

#include "Player.hpp"
using namespace std;

class Alchemist : public Player {
    private:
        BattleBoard board;
        BattleRules rules = NULL;
    public:
        Alchemist(BattleBoard *board, BattleRules *rules, char m);
        void move() override;
        void prompt() override;
        char mark;
};