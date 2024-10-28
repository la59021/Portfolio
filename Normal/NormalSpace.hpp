#pragma once
class NormalSpace {
    public:
        NormalSpace();
        int getStatus();
        void setStatus(int newState);
    private:
        int state = 0;
};