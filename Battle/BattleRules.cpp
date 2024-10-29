#include "BattleRules.hpp"
using namespace std;

BattleRules::BattleRules() {
    this->board = new Board();
}

BattleRules::BattleRules(Board *board) {
    this->board = board;
}

bool BattleRules::follows_rules(char rowChar, char colChar) {
    if (board->valid_inputs(rowChar, colChar)) {
        int index = board->change_to_index(rowChar, colChar);
        if (board->empty_space(index)) {
            return true;
        }
    }
    return false;
}

bool BattleRules::was_there_a_winner() {
    if (check_for_win() != "") {
        string winner = check_for_win();
        winner = winner[sizeof(winner) - 2];
        string winningCombo = winner;
        winningCombo.resize(sizeof(winningCombo) - 2);
        if (winner == "1") {
            responses.winner_is_player_1();
        }
        if (winner == "2") {
            responses.winner_is_player_2();
        }
        cout << winningCombo << endl;
        won = true;
        return true;
    }
    return false;
}

bool BattleRules::check_for_tie() {
    bool allFull = true;
    for (int i = 1; i <= board->get_length(); i++) {
        if (board->get_space_status(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && check_for_win() == "") {
        responses.game_was_tie();
        return true;
    }
    return false;
}

bool BattleRules::play_again() {
    char reply = 'N';
    prompts.ask_to_play_again();
    cin >> reply;
    if (reply == 'Y' || reply == 'y') {
        for (int i = 1; i <= board->get_length(); i++) {
            board->set_space_status(i, 0);
        }
        return true;
    }
    return false;
}

string BattleRules::check_for_win() {
    string reply = "";
    for (int i = 1; i < 3; i++) {
        if (board->get_space_status(1) == i) {
            if (board->get_space_status(2) == i) {
                if (board->get_space_status(3) == i) {
                    reply = "The Winning combo was (1, A), (1, B), (1, C)." + to_string(i);
                }
            }
            if (board->get_space_status(4) == i) {
                if (board->get_space_status(7) == i) {
                    reply = "The Winning combo was (1, A), (2, A), (3, A)." + to_string(i);
                }
            }
            if (board->get_space_status(5) == i) {
                if (board->get_space_status(9) == i) {
                    reply = "The Winning combo was (1, A), (2, B), (3, C)." + to_string(i);
                }
            }
        }
        if (board->get_space_status(2) == i) {
            if (board->get_space_status(5) == i) {
                if (board->get_space_status(8) == i) {
                    reply = "The Winning combo was (1, B), (2, B), (3, B)." + to_string(i);
                }
            }
        }
        if (board->get_space_status(3) == i) {
            if (board->get_space_status(5) == i) {
                if (board->get_space_status(7) == i) {
                    reply = "The Winning combo was (1, C), (2, B), (3, A)." + to_string(i);
                }
            }
            if (board->get_space_status(6) == i) {
                if (board->get_space_status(9) == i) {
                    reply = "The Winning combo was (1, C), (2, C), (3, C)." + to_string(i);
                }
            }
        }
        if (board->get_space_status(4) == i) {
            if (board->get_space_status(5) == i) {
                if (board->get_space_status(6) == i) {
                    reply = "The Winning combo was (2, A), (2, B), (2, C)." + to_string(i);
                }
            }
        }
        if (board->get_space_status(7) == i) {
            if (board->get_space_status(8) == i) {
                if (board->get_space_status(9) == i) {
                    reply = "The Winning combo was (3, A), (3, B), (3, C)." + to_string(i);
                }
            }
        }
    }
    return reply;
}