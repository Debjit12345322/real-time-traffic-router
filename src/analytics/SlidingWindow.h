#pragma once
#include <deque>
using namespace std;

class SlidingWindow {
    int W;
    deque<int> dq;
    int sum;

public:
    SlidingWindow(int W);
    void add(int x);
    double average();
};
