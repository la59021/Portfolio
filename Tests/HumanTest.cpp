#include "../Common/Board.hpp"
#include "../Normal/NormalRules.hpp"
#include "../Classes/Human.hpp"
#include "../Classes/Player.hpp"
using namespace std;

int main() {
    Board board;
    NormalRules rules = NormalRules(&board);
    Human player1 = Human(&board, &rules, 'X');
    Human player2 = Human(&board, &rules, '0');
    player1.turn();
    player2.turn();
    return 0;
}