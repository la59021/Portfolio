#pragma once

class NSpace {
    public:
        NSpace();
        int getStatus();
        void setStatus(int newState);
    private:
        int state;
};