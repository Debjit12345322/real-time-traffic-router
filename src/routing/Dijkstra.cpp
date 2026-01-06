#include "Dijkstra.h"

#include <queue>
#include <limits>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

vector<int> Dijkstra::shortestPath(
    Graph &g,
    SegmentTree &traffic,
    int src
) {
    int n = g.n;
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (const auto &e : g.adj[u]) {
            int w = e.base_weight + traffic.query(e.edge_id);
            if (dist[e.to] > d + w) {
                dist[e.to] = d + w;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}
