class BattleSpace {
    public:
        BattleSpace();
        int getStatus();
        void setStatus(int newState);

    private:
        int state = 0;
};
