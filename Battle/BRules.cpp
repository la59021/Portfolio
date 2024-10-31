#include "../Terminate.cpp"
#include "BRules.hpp"
using namespace std;

BRules::BRules(BBoard *board) {
    this->board = board;
    responses = BResponses(board);
    printer = BBoardPrinter(board);
}

void BRules::addPlayers(Player *player1, Player *player2) {
    this->player1 = player1;
    this->player2 = player2;
    printer.setMarks(player1->get_mark(), player2->get_mark());
}
 
bool BRules::followsRules(const char rowChar, const char colChar) {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
    for (int i = 0; i < sizeof(rowRange); i++) {
        if (rowChar == rowRange[i]) {
            for (int x = 0; x < sizeof(colRange); x++) {
                if (colChar == colRange[x]) {
                    int index = changeToIndex(rowChar, colChar);
                    if (this->board->getSpaceStatus(index) == 0) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int BRules::gameInProgress() {
    return !won;
}

void BRules::player1Turn() {
    char validMenuOptions[] = {'1','2','3'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    printer.printBoard();
    player1->prompt();
    cin >> reply;
    for(unsigned i = 0; i < sizeof(validMenuOptions); i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == '1') {
        player1Move();
    }
    if (validSelection && reply == '2') {
        player1->skill();
    }   
    if (validSelection && reply == '3') {
        cout << player1->desc();
        goto prompt;
    }
    if (validSelection && reply == '4') {
        throw stop_now_t();
    }
}

void BRules::player2Turn() {
    player2Move();
}

void BRules::player1Move() {
    int index = 10;
    char rowChar, colChar;
    /* if (checkForWin() != "") {
        won = true;
    }
    if (checkForWin() == "") {
        goto start;
    }
    else {
        goto leave;
    } */
    start:
        printer.printBoard();
        prompts.askForXSpace();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules(rowChar, colChar))) {
            index = changeToIndex(rowChar, colChar);
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        board->setSpaceStatus(index, 1);
        if (!won && checkForWin() != "") {
            printer.printBoard();
            responses.winnerIsX();
            cout << checkForWin() << endl;
            won = true;
        }
        else {
        }

    leave:
    index = 0; // just to get the compiler to shutup about the label at the end
}

void BRules::player2Move() {
    int index = 10;
    char rowChar, colChar;
    /* if (checkForWin() != "") {
        won = true;
    }
    if (checkForWin() == "") {
        goto start;
    }
    else {
        goto leave;
    } */
    start:
        printer.printBoard();
        player2->prompt();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules(rowChar, colChar))) {
            index = changeToIndex(rowChar, colChar);
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        this->board->setSpaceStatus(index, 2);
        if (!won && checkForWin() != "") {
            printer.printBoard();
            responses.winnerIsO();
            cout << checkForWin() << endl;
            won = true;
        }
        else {
        }
    leave:
    index = 0; // just to get the compiler to shutup about the label at the end
}

bool BRules::checkForTie() {
    bool allFull = true;
    for (int i = 1; i <= board->getLength(); i++) {
        if (board->getSpaceStatus(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && checkForWin() == "") {
        printer.printBoard();
        responses.gameWasTie();
        return true;
    }
    return false;
}

bool BRules::checkForWin() {
    int toCheck;
    if (board->getSpaceStatus(1) == (board->getSpaceStatus(2) && board->getSpaceStatus(3))) {
        return true;
    }
    if (board->getSpaceStatus(1) == (board->getSpaceStatus(4) && board->getSpaceStatus(4))) {
        return true;
    }
    if (board->getSpaceStatus(1) == (board->getSpaceStatus(5) && board->getSpaceStatus(9))) {
        return true;
    }
    if (board->getSpaceStatus(2) == (board->getSpaceStatus(5) && board->getSpaceStatus(8))) {
        return true;
    }
    if (board->getSpaceStatus(3) == (board->getSpaceStatus(5) && board->getSpaceStatus(7))) {
        return true;
    }
    toCheck = board->getSpaceStatus(3);
    if (board->getSpaceStatus(3) == toCheck) {
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(7) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, C), (2, B), (3, A).";
            }
        }
        if (board->getSpaceStatus(6) == toCheck) {
            if (board->getSpaceStatus(9) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, C), (2, C), (3, C).";
            }
        }
    }
    toCheck = board->getSpaceStatus(4);
    if (board->getSpaceStatus(4) == toCheck) {
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(6) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (2, A), (2, B), (2, C).";
            }
        }
    }
    toCheck = board->getSpaceStatus(7);
    if (board->getSpaceStatus(7) == toCheck) {
        if (board->getSpaceStatus(8) == toCheck) {
            if (board->getSpaceStatus(9) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (3, A), (3, B), (3, C).";
            }
        }
    }
    return reply;
}

/* string BRules::checkForWin() {
    string reply = "";
    int toCheck;
    toCheck = board->getSpaceStatus(1);
    if (board->getSpaceStatus(1) == toCheck) {
        if (board->getSpaceStatus(2) == toCheck) {
            if (board->getSpaceStatus(3) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply += "The Winning combo was (1, A), (1, B), (1, C).";
            }
        }
        if (board->getSpaceStatus(4) == toCheck) {
            if (board->getSpaceStatus(7) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, A), (2, A), (3, A).";
            }
        }
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(9) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, A), (2, B), (3, C).";
            }
        }
    }
    toCheck = board->getSpaceStatus(2);
    if (board->getSpaceStatus(2) == toCheck) {
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(8) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, B), (2, B), (3, B).";
            }
        }
    }
    toCheck = board->getSpaceStatus(3);
    if (board->getSpaceStatus(3) == toCheck) {
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(7) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, C), (2, B), (3, A).";
            }
        }
        if (board->getSpaceStatus(6) == toCheck) {
            if (board->getSpaceStatus(9) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (1, C), (2, C), (3, C).";
            }
        }
    }
    toCheck = board->getSpaceStatus(4);
    if (board->getSpaceStatus(4) == toCheck) {
        if (board->getSpaceStatus(5) == toCheck) {
            if (board->getSpaceStatus(6) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (2, A), (2, B), (2, C).";
            }
        }
    }
    toCheck = board->getSpaceStatus(7);
    if (board->getSpaceStatus(7) == toCheck) {
        if (board->getSpaceStatus(8) == toCheck) {
            if (board->getSpaceStatus(9) == toCheck) {
                if (toCheck == 1) {
                    reply += "The winner was Player1.\n"; 
                }
                if (toCheck == 2) {
                    reply += "The winner was Player2.\n"; 
                }
                reply = "The Winning combo was (3, A), (3, B), (3, C).";
            }
        }
    }
    return reply;
} */

int BRules::changeToIndex(const char rowChar, const char colChar) {
    int index;
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
    return index;
}