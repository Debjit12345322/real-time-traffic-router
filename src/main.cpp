#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <utility>
#include <functional>
using namespace std;

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

    Graph(int n) : n(n), adj(n) {}

    void addEdge(int u, int v, int w, int id) {
        adj[u].push_back({v, w, id});
    }
};


class TrafficManager {
    vector<int> delay;

public:
    TrafficManager(int m) : delay(m, 0) {}

    void update(int edge_id, int val) {
        delay[edge_id] = val;
    }

    int query(int edge_id) const {
        return delay[edge_id];
    }
};


vector<int> dijkstra(const Graph &g, const TrafficManager &traffic, int src) {
    const int INF = 1e9;
    vector<int> dist(g.n, INF);
    dist[src] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push(make_pair(0, src));

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
                pq.push(make_pair(dist[e.to], e.to));
            }
        }
    }
    return dist;
}



int main() {
    ifstream fin("data/graph.txt");
    if (!fin) {
        cerr << "Error: graph.txt not found\n";
        return 1;
    }

    int N, M;
    fin >> N >> M;

    Graph g(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        g.addEdge(u, v, w, i);
    }

    TrafficManager traffic(M);

    int Q;
    fin >> Q;

    while (Q--) {
        string cmd;
        fin >> cmd;

        if (cmd == "UPDATE") {
            int id, val;
            fin >> id >> val;
            traffic.update(id, val);
        }
        else if (cmd == "QUERY") {
            int s, d;
            fin >> s >> d;
            auto dist = dijkstra(g, traffic, s);
            cout << (dist[d] >= 1e9 ? -1 : dist[d]) << "\n";
        }
    }

    fin.close();
    return 0;
}
