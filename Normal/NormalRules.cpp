#include "NormalRules.hpp"
using namespace std;

NormalRules::NormalRules() {
    index = 10;
    winner = 0;
}

bool NormalRules::follows_rules() {
    if (input_is_in_range()) {
        change_to_index();
        if (space_is_open()) {
           return true;
        }
    }
    return false;
}

bool NormalRules::was_there_a_winner() {
    return won;
}

void NormalRules::take_X_turn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (check_for_win(true) != "" || check_for_win(false) != "") {
        won = true;
    }
    if (check_for_win(true) == "" && check_for_win(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.print_board(board);
        prompts.ask_for_X_space();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((follows_rules())) {
            change_to_index();
            goto valid;
        }
        else {
            responses.is_invalid_space();
            responses.print_board(board);
            goto start;

        }

    valid:
        board.set_space_status(index, 1);
        if (!won && check_for_win(true) != "") {
            responses.winner_is_X();
            cout << check_for_win(true) << endl;
            won = true;
        }
        else {
        }
        
    leave:
    int x = 0;
}

void NormalRules::take_O_turn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (check_for_win(true) != "" || check_for_win(false) != "") {
        won = true;
    }
    if (check_for_win(true) == "" && check_for_win(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.print_board(board);
        prompts.ask_for_O_space();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((follows_rules())) {
            change_to_index();
            goto valid;
        }
        else {
            responses.is_invalid_space();
            responses.print_board(board);
            goto start;

        }

    valid:
        board.set_space_status(index, 2);
        if(!won && check_for_win(false) != "") {
            responses.winner_is_O();
            cout << check_for_win(false) << endl;
            won = true;
        }
        else {
        }
    leave:
    int x = 0;
}

bool NormalRules::check_for_tie() {
    bool allFull = true;
    for (int i = 1; i <= board.get_length(); i++) {
        if (board.get_space_status(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && check_for_win(true) == "" && check_for_win(false) == "") {
        responses.printBoard(board);
        responses.gameWasTie();
        return true;
    }
    return false;
}

bool NormalRules::play_again() {
    char reply = 'N';
    prompts.ask_to_play_again();
    cin >> reply;
    if (reply == 'Y' || reply == 'y') {
        for (int i = 1; i <= board.get_length(); i++) {
            board.set_space_status(i, 0);
        }
        return true;
    }
    return false;
}

int NormalRules::get_last_winner() {
    return winner;
}

bool NormalRules::input_is_in_range() {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
    for (int i = 0; i < rowRange.size() ; i++) {
        if (rowChar == rowRange[i]) {
            for (int x = 0; x < colRange.size(); x++) {
                if (colChar == colRange[x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool NormalRules::space_is_open() {
    if (board.get_space_status(index) == 0) {
        return true;
    }
    return false;
}

string NormalRules::check_for_win(bool checkingX) {
    string reply = "";
    int toCheck = 2;
    if (checkingX) {
        toCheck = 1;
    }
    if (board.get_space_status(1) == toCheck) {
        if (board.get_space_status(2) == toCheck) {
            if (board.get_space_status(3) == toCheck) {
                reply = "The Winning combo was (1, A), (1, B), (1, C).";
            }
        }
        if (board.get_space_status(4) == toCheck) {
            if (board.get_space_status(7) == toCheck) {
                reply = "The Winning combo was (1, A), (2, A), (3, A).";
            }
        }
        if (board.get_space_status(5) == toCheck) {
            if (board.get_space_status(9) == toCheck) {
                reply = "The Winning combo was (1, A), (2, B), (3, C).";
            }
        }
    }
    if (board.get_space_status(2) == toCheck) {
        if (board.get_space_status(5) == toCheck) {
            if (board.get_space_status(8) == toCheck) {
                reply = "The Winning combo was (1, B), (2, B), (3, B).";
            }
        }
    }
    if (board.get_space_status(3) == toCheck) {
        if (board.get_space_status(5) == toCheck) {
            if (board.get_space_status(7) == toCheck) {
                reply = "The Winning combo was (1, C), (2, B), (3, A).";
            }
        }
        if (board.get_space_status(6) == toCheck) {
            if (board.get_space_status(9) == toCheck) {
                reply = "The Winning combo was (1, C), (2, C), (3, C).";
            }
        }
    }
    if (board.get_space_status(4) == toCheck) {
        if (board.get_space_status(5) == toCheck) {
            if (board.get_space_status(6) == toCheck) {
                reply = "The Winning combo was (2, A), (2, B), (2, C).";
            }
        }
    }
    if (board.get_space_status(7) == toCheck) {
        if (board.get_space_status(8) == toCheck) {
            if (board.get_space_status(9) == toCheck) {
                reply = "The Winning combo was (3, A), (3, B), (3, C).";
            }
        }
    }
    if (reply != "") {
        winner = toCheck;
    }
    return reply;
}

void NormalRules::change_to_index() {
    if (rowChar == '1') {
        index = 1;
    }
    else if (rowChar == '2') {
        index = 4;
    }
    else {
        index = 7;
    }

    if (colChar == 'A' || colChar == 'a') {
        index += 0;
    }
    else if (colChar == 'B' || colChar == 'b') {
        index += 1;
    }
    else if (colChar == 'C' || colChar == 'c') {
        index += 2;
    }
}
