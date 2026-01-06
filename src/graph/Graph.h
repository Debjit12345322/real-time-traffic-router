#pragma once
#include <vector>
using namespace std;

struct Edge {
    int to;
    int base_weight;
    int edge_id;
};

class Graph {
public:
    int n;
    vector<vector<Edge>> adj;

    Graph(int n);
    void addEdge(int u, int v, int w, int id);
};
