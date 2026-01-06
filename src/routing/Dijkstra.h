#pragma once
#include "../graph/Graph.h"
#include "../traffic/SegmentTree.h"
#include <vector>
using namespace std;

class Dijkstra {
public:
    static vector<int> shortestPath(
        Graph &g,
        SegmentTree &traffic,
        int src
    );
};
