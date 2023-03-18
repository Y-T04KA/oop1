#pragma once
#include <matrix.h>

class App {
public:
    void welcome();
private:
    int state = 0;
    void enter();
    void deter();
    void trans();
    void rank();
    void move(int state);
    void current();
    matrix instance;
};
