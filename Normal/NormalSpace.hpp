#ifndef NORMALSPACE_HPP
#define NORMALSPACE_HPP
class NormalSpace {
    public:
        NormalSpace();
        int getStatus();
        void setStatus(int newState);
    private:
        int state = 0;
};
#endif