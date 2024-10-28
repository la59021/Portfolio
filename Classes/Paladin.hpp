#include "../Battle/BattleRules.hpp"

#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    public:
        Paladin(Board *board, BattleRules *rules, char m);
        void move() override;
        void prompt() override;
        char get_mark() override;
    private:
        char mark;
        Board *board;
        BattleRules *rules;
};