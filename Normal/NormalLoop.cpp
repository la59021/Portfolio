#include <array>
#include "NormalLoop.hpp"
using namespace std;

void NormalLoop::start() {
    this->board = new Board();
    this->rules = new NormalRules(this->board);
    this->responses = new NormalResponses(this->board);
    create_players();
    board->add_marks(player1->get_mark(), player2->get_mark());
    int turncount = 0;
    while(this->rules->game_in_progress()) {
        if (turncount % 2 == 0) {
            player1->turn();
        }
        else if (turncount % 2 != 0) {
            player2->turn();
        }
    }
    if(play_again()) {

    }
}

void NormalLoop::create_players() {
    player1 = new Human(this->board, this->rules, 'X');
    player2 = new Human(this->board, this->rules, 'O');
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