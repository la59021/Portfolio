#include "ClassMenu.hpp"
#include "CharMenu.hpp"
#include <array>

#include "BattleLoop.hpp"
using namespace std;

void BattleLoop::start() {
    this->board = new BattleBoard();
    this->rules = new BattleRules(board);
    this->prompts = new BattlePrompts();
    this->responses = new BattleResponses(board);
    create_players();
    int turncount = 0;
    while(this->board->unfilled_spaces() == true && this->rules->was_there_a_winner() == false) {
        if (turncount % 2 == 0) {
            take_player_1_turn();
        }
        else if (turncount % 2 != 0) {
            take_player_2_turn();
        }
    }        
}

void BattleLoop::create_players() {
    ClassMenu classMenu = ClassMenu();
    CharMenu charMenu = CharMenu();
    array<int, 2> classes = classMenu.player_classes();
    array<char, 2> marks = charMenu.player_chars();
    for (int x = 0; x < 2; x++) {
        if (x == 0) {
            if (classes[x] == 1) {
                player1 = new Paladin(this->board, this->rules, marks[x]);
            }
            if (classes[x] == 2) {
                player1 = new Alchemist(this->board, this->rules, marks[x]);
            }
        }
        else if (x == 1) {
            if (classes[x] == 1) {
                player2 = new Paladin(this->board, marks[x]);
            }
            if (classes[x] == 2) {
                player2 = new Alchemist(this->board, marks[x]);
            }
        }
    }
}

void BattleLoop::take_player_1_turn() {
    int index = 10;
    char rowChar = 'R';
    char colChar = 'C';
    start:
    this->responses->print_board();
    this->player1->prompt();
}

void BattleLoop::take_player_2_turn() {
    int index = 10;
    char rowChar = 'R';
    char colChar = 'C';
    start:
    this->responses->print_board();
    this->prompts->ask_for_player_2_space();
    cin >> rowChar;
    cin >> colChar;
    cout << endl;
    goto checkValidity;

    checkValidity:
    if (this->rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        this->responses->is_invalid_space();
        this->responses->print_board();
        goto start;
    }
    
    valid:
    this->board->set_space_status(index, 2);
}