#include "BattleRules.hpp"
using namespace std;

BattleRules::BattleRules(BattleBoard *board) {
    this->board = board;
    winner = 0;
}

bool BattleRules::was_there_a_winner() {
    return won;
}

bool BattleRules::check_for_tie() {
    bool allFull = true;
    for (int i = 1; i <= board->get_length(); i++) {
        if (board->get_space_status(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && check_for_win(true) == "" && check_for_win(false) == "") {
        responses.print_board(board);
        responses.game_was_tie();
        return true;
    }
    return false;
}

bool BattleRules::play_again() {
    char reply = 'N';
    prompts.askToPlayAgain();
    cin >> reply;
    if (reply == 'Y' || reply == 'y') {
        for (int i = 1; i <= board.getLength(); i++) {
            board.setSpaceStatus(i, 0);
        }
        return true;
    }
    return false;
}

string BattleRules::check_for_win(bool checkingX) {
    string reply = "";
    int toCheck = 2;
    if (checkingX) {
        toCheck = 1;
    }
    if (board.getSpaceStatus(1) == toCheck) {
        if (board.getSpaceStatus(2) == toCheck) {
            if (board.getSpaceStatus(3) == toCheck) {
                reply = "The Winning combo was (1, A), (1, B), (1, C).";
            }
        }
        if (board.getSpaceStatus(4) == toCheck) {
            if (board.getSpaceStatus(7) == toCheck) {
                reply = "The Winning combo was (1, A), (2, A), (3, A).";
            }
        }
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (1, A), (2, B), (3, C).";
            }
        }
    }
    if (board.getSpaceStatus(2) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(8) == toCheck) {
                reply = "The Winning combo was (1, B), (2, B), (3, B).";
            }
        }
    }
    if (board.getSpaceStatus(3) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(7) == toCheck) {
                reply = "The Winning combo was (1, C), (2, B), (3, A).";
            }
        }
        if (board.getSpaceStatus(6) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (1, C), (2, C), (3, C).";
            }
        }
    }
    if (board.getSpaceStatus(4) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(6) == toCheck) {
                reply = "The Winning combo was (2, A), (2, B), (2, C).";
            }
        }
    }
    if (board.getSpaceStatus(7) == toCheck) {
        if (board.getSpaceStatus(8) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (3, A), (3, B), (3, C).";
            }
        }
    }
    if (reply != "") {
        winner = toCheck;
    }
    return reply;
}