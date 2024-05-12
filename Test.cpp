#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Empty graph properties") {
    Graph g;
    vector<vector<int>> emptyGraph = {};
    CHECK_THROWS(g.loadGraph(emptyGraph)); 

    g.loadGraph(emptyGraph); 
    CHECK(Algorithms::isConnected(g) == false);
    CHECK(Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");
}

TEST_CASE("Single vertex graph properties") {
    Graph g;
    vector<vector<int>> singleVertex = {{0}};
    g.loadGraph(singleVertex);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={}");
}

TEST_CASE("Graph with one edge") {
    Graph g;
    vector<vector<int>> oneEdge = {{0, 1}, {1, 0}};
    g.loadGraph(oneEdge);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
}

TEST_CASE("Simple cycle graph") {
    Graph g;
    vector<vector<int>> cycleGraph = {{0, 1}, {1, 0}};
    g.loadGraph(cycleGraph);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Complex connected graph") {
    Graph g;
    vector<vector<int>> complex = {{0, 1, 1}, {1, 0, 0}, {1, 0, 0}};
    g.loadGraph(complex);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Fully connected graph") {
    Graph g;
    vector<vector<int>> fullyConnected = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    g.loadGraph(fullyConnected);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Large bipartite graph") {
    Graph g;
    vector<vector<int>> bipartiteLarge = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};
    g.loadGraph(bipartiteLarge);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isBipartite(g).find("The graph is bipartite") != string::npos);
}

TEST_CASE("Graph with self-loops") {
    Graph g;
    vector<vector<int>> selfLoops = {{1, 0}, {0, 1}};
    g.loadGraph(selfLoops);
    CHECK(Algorithms::isConnected(g) == false);
    CHECK(Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Disconnected graph") {
    Graph g;
    vector<vector<int>> disconnected = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    g.loadGraph(disconnected);
    CHECK(Algorithms::isConnected(g) == false);
    CHECK(Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={}");
}

TEST_CASE("Negative weight graph") {
    Graph g;
    vector<vector<int>> negativeWeights = {{0, -1, -3}, {-1, 0, -2}, {-3, -2, 0}};
    g.loadGraph(negativeWeights);
    vector<int> distances;
    CHECK_NOTHROW(Algorithms::bellmanFord(g, 0, distances));
}