#include "../Battle/BattleRules.hpp"

#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    public:
        Paladin(Board *board, BattleRules *rules, char m);
        void turn() override;
        void move() override;
        void skill();
        void prompt() override;
        int prompt_selection();
        char get_mark() override;
    private:
        char mark;
        Board *board;
        BattleRules *rules;
};