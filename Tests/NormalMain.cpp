#include "../Normal/NGame.hpp"
#include "../Terminate.cpp"
using namespace std;

int main() {
    NGame game;
    try {
        game.startGame();
    } catch (stop_now_t& stop) {
        return 0;
    }
    return 0;
}