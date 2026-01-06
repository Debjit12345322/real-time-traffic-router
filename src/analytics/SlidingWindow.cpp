#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(int W) : W(W), sum(0) {}

void SlidingWindow::add(int x) {
    dq.push_back(x);
    sum += x;
    if (dq.size() > W) {
        sum -= dq.front();
        dq.pop_front();
    }
}

double SlidingWindow::average() {
    if (dq.empty()) return 0;
    return (double)sum / dq.size();
}
