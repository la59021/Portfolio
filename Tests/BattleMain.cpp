#include "../Battle/BGame.hpp"
#include "../Terminate.cpp"
using namespace std;

int main() {
    try {
        BGame bGame;
        bGame.startGame();
    } catch (stop_now_t& stop) {
        return 0;
    }
    return 0;
}