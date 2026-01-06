#include "SegmentTree.h"

SegmentTree::SegmentTree(int n) : n(n) {
    tree.assign(4 * n, 0);
}

void SegmentTree::update(int idx, int value) {
    int i = idx + n;
    tree[i] = value;
}

int SegmentTree::query(int idx) {
    return tree[idx + n];
}
