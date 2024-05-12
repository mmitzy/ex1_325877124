# Graph Algorithms Implementation

This project demonstrates the implementation of various graph algorithms using an adjacency matrix representation. It's designed to showcase the practical application of these algorithms in real-world scenarios.

## Algorithms

The project includes implementations of several fundamental graph algorithms:

- `isConnected(graph)`: Determines if the graph is connected.
- `shortestPath(graph, start, end)`: Finds the shortest path between two nodes.
- `containsCycle(graph)`: Checks for the presence of cycles.
- `negativeCycle(graph)`: Detects negative cycles.
- `isBipartite(graph)`: Verifies if the graph is bipartite.

## Graph Representation

The graph is represented using an adjacency matrix, facilitating efficient computation of graph properties and algorithms.

- `loadGraph(matrix)`: Initializes the graph with a given adjacency matrix.
- `printGraph()`: Outputs a textual representation of the graph.
- `getNeighbors(node)`: Retrieves the neighbors of a specified node.

## Usage

To utilize the project, include the necessary headers and follow the provided namespace conventions. Here's a basic example:

#include "Graph.hpp" #include "Algorithms.hpp" using namespace GraphNamespace; #include <iostream> #include <vector> using namespace std;

int main() { Graph g; vector<vector<int>> graph = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}; g.loadGraph(graph);

g.printGraph();
cout << isConnected(g) << endl;
cout << shortestPath(g, 0, 2) << endl;
cout << containsCycle(g) << endl;
cout << isBipartite(g) << endl;
// Additional graph manipulation and algorithm usage...
return 0;
