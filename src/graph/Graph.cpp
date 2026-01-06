#include "Graph.h"

Graph::Graph(int n) : n(n) {
    adj.resize(n);
}

void Graph::addEdge(int u, int v, int w, int id) {
    adj[u].push_back({v, w, id});
}
