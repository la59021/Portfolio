#include <array>
#include "NormalLoop.hpp"
using namespace std;

void NormalLoop::start() {
    this->board = new Board();
    this->rules = new NormalRules(this->board);
    this->responses = new NormalResponses(this->board);
    create_players();
    int turncount = 0;
    while(this->rules->game_in_progress()) {
        if (turncount % 2 == 0) {
            take_player_1_turn();
        }
        else if (turncount % 2 != 0) {
            take_player_2_turn();
        }
    }
    if(play_again()) {

    }
}

void NormalLoop::create_players() {
    player1 = new Human(this->board, this->rules, 'X');
    player2 = new Human(this->board, this->rules, 'O');
}

void NormalLoop::take_player_1_turn() {
    int index;
    char rowChar, colChar;
    start:
    this->responses->print_board();
    this->player1->prompt();
    cin >> rowChar;
    cin >> colChar;
    cout << endl;

    checkValidity:
    if (this->rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        cout << "The entered space was invalid" << endl;
        goto start;
    }
    
    valid:
    this->board->set_space_status(index, 1);
}

void NormalLoop::take_player_2_turn() {
    int index;
    char rowChar, colChar;
    start:
    this->responses->print_board();
    this->player2->prompt();
    cin >> rowChar;
    cin >> colChar;
    cout << endl;

    checkValidity:
    if (this->rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        cout << "The entered space was invalid" << endl;
        goto start;
    }
    
    valid:
    this->board->set_space_status(index, 2);
}

bool NormalLoop::play_again() {
    char reply;
    cout << "Would you like to play Again? Y/N:" << endl;
    cin >> reply;
    if (reply == 'Y' || reply == 'y') {
        for (int i = 1; i <= board->get_length(); i++) {
            board->set_space_status(i, 0);
        }
        return true;
    }
    return false;
}