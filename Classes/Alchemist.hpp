#include "../Battle/BattleRules.hpp"
#include "Player.hpp"
using namespace std;

class Alchemist : public Player {
    public:
        Alchemist(Board *board, BattleRules *rules, char m);
        void move() override;
        void prompt() override;
        char get_mark() override;
    private:
        char mark;
        Board *board;
        BattleRules *rules;
};

/*
start:
    cin >> rowChar;
    cin >> colChar;
    cout << endl;
    goto checkValidity;

    checkValidity:
    if (this->*rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        this->responses->is_invalid_space();
        this->responses->print_board();
        goto start;
    }

    valid:
    this->board->set_space_status(index, 1);
*/