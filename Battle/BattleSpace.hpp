#ifndef BATTLESPACE_HPP
#define BATTLESPACE_HPP
class BattleSpace {
    public:
        BattleSpace();
        int getStatus();
        void setStatus(int newState);

    private:
        int state = 0;
};
#endif