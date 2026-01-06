Real Time Traffic Aware Route Optimization Engine

This project implements a real time routing system in C++ that computes shortest paths on a road network while considering traffic delays. Cities are represented as nodes and roads are represented as weighted edges in a graph.

The project focuses on how shortest path algorithms can be adapted when edge weights change dynamically due to traffic conditions.

Features

Graph based representation of cities and roads

Dijkstra’s algorithm for shortest path computation

Dynamic traffic delay updates on individual roads

Multiple roads allowed between the same pair of cities

File based input for easy testing and reproducibility

Basic Idea

Each road has a base cost which represents the normal travel time.
Traffic is handled by adding a dynamic delay to this base cost.

The effective cost of a road during routing is:
base weight + traffic delay

Traffic delays are stored separately and are applied during the shortest path computation. The graph structure itself is not modified.
Input Format

The input is read from data/graph.txt.

Graph Definition
N M
u v w


N is the number of cities (nodes)

M is the number of roads (edges)

u and v represent a directed road from u to v

w is the base cost of the road

Each road is assigned an edge id based on its input order.

Operations

After the graph definition, the input contains a number of operations.

Q


Each operation is one of the following:

Traffic Update
UPDATE edge_id delay


This updates the traffic delay on the given road.

Shortest Path Query
QUERY source destination


This computes the shortest distance from source to destination considering current traffic.

Example Input
6 5 |
0 1 5 |
1 2 3 |
0 3 10 |
3 4 1 |
4 2 2 |
7 |
UPDATE 1 4 |
QUERY 0 2 |
UPDATE 3 6 |
QUERY 0 2 |
UPDATE 1 0 |
QUERY 3 2 |
QUERY 0 4 |

Output

For each QUERY operation, the program prints one line containing the shortest distance.

12 |
12 |
9 |
17 |


base weight + traffic delay

Traffic delays are stored separately and are applied during the shortest path computation. The graph structure itself is not modified.
