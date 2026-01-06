#pragma once
#include <vector>
using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n);
    void update(int idx, int value);
    int query(int idx);
};
