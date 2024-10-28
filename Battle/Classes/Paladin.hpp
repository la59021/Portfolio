#include "../../Common/Board.hpp"
#include "../BattleRules.hpp"

#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    private:
    public:
        Paladin(Board *board, BattleRules *rules, char m);
        void move() override;
        void prompt() override;
        char mark;
};