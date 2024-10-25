#include "BattlePrompts.hpp"
#include "BattleResponses.hpp"
#include "BattleBoard.hpp"
using namespace std;

class BattleRules {
    public:
        BattleRules(BattleBoard *board);
        bool follows_rules();
        bool was_there_a_winner();
        bool check_for_tie();
        bool play_again();
        int get_last_winner();
    private:
        BattleBoard *board;
        Prompts prompts = Prompts();
        BattleResponses responses;
        bool won = false;
        string check_for_win();
};
