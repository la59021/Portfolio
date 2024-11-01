#include "../Normal/NBoard.hpp"
#include "../Normal/NPromptsAndResponses.hpp"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    NBoard board;
    board.setSpaceStatus(1, 1);
    board.setSpaceStatus(2, 2);
    board.setSpaceStatus(3, 1);
    board.setSpaceStatus(4, 2);
    board.setSpaceStatus(5, 1);
    board.setSpaceStatus(6, 2);
    board.setSpaceStatus(7, 1);
    board.setSpaceStatus(8, 2);
    board.setSpaceStatus(9, 1);
    // setting up redirection of cout
    // from https://truong.io/posts/capturing_stdout_for_c++_unit_testing.html
    string expected;
    expected = "  |  A  |  B  |  C  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "1 |  X  |  O  |  X  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "2 |  O  |  X  |  O  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "3 |  X  |  O  |  X  |  \n";
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    NResponses printer(&board);
    printer.printBoard();
    string text = buffer.str();
    cout.rdbuf(prevcoutbuf);
    cout << text;
    cout << expected;
    assert(text == expected);
    return 0;
}