🚦 Real-Time Traffic-Aware Route Optimization Engine

This project implements a real-time traffic-aware routing system in C++.
It models cities and roads as a weighted graph and computes shortest paths while dynamically accounting for traffic delays on individual roads.

The goal of this project is to simulate how modern navigation systems adapt routes in response to changing traffic conditions, using efficient graph algorithms and data structures.

✨ Features

Graph-based representation of cities and roads

Dijkstra’s algorithm for shortest path computation

Dynamic traffic delay updates on individual roads

Multiple edges allowed between the same pair of cities

File-based input for reproducible experiments

Efficient handling of multiple queries

🧠 Core Idea

Each road is represented as an edge with:

a base weight (distance or free-flow travel time)

a dynamic traffic delay that can change over time

The effective weight used during routing is:

effective_weight = base_weight + traffic_delay


Traffic delays are not added as new edges.
Instead, they are stored separately and applied dynamically during path computation.

🗂 Project Structure
real-time-traffic-router/
│
├── src/
│   └── main.cpp
│
├── data/
│   └── graph.txt
│
├── README.md
└── .gitignore

📄 Input Format (data/graph.txt)
Graph Definition
N M
u v w   (M lines)


N = number of cities (nodes)

M = number of roads (edges)

u → v = directed road from city u to city v

w = base travel cost

Each road is automatically assigned an edge_id based on input order.

Operations
Q
<operation 1>
<operation 2>
...
<operation Q>

Traffic Update
UPDATE edge_id delay

Shortest Path Query
QUERY source destination

🧪 Example Input
6 5
0 1 5
1 2 3
0 3 10
3 4 1
4 2 2
7
UPDATE 1 4
QUERY 0 2
UPDATE 3 6
QUERY 0 2
UPDATE 1 0
QUERY 3 2
QUERY 0 4

📤 Output

For each QUERY, the program prints the shortest distance:

12
12
9
17

⚙️ How to Compile and Run
Windows (MinGW / PowerShell)
g++ -std=gnu++11 -O2 src/main.cpp -o router.exe -mconsole
.\router.exe


Make sure graph.txt is present inside the data/ folder.

⏱ Time & Space Complexity

Dijkstra’s Algorithm:
O(E log V) per query

Traffic Update:
O(1)

Graph Size Supported:
Up to ~10,000 nodes and ~100,000 edges (practical limits)

🧩 Design Highlights

Traffic delays are associated with edges, not node pairs

Multiple roads between the same cities are handled correctly

Graph structure remains static; only edge costs change dynamically

Clean separation between graph, traffic, and routing logic

🚀 Possible Extensions

Path reconstruction (actual route, not just distance)

A* algorithm with heuristic optimization

Time-dependent traffic profiles (rush hours)

Benchmarking and performance analysis

CMake-based build system
