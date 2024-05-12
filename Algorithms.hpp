#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Algorithms{
        private:
            vector<vector<int>> curr_graph;
            static bool dfs(ariel::Graph g, int s, vector<bool> &visited, vector<bool> &recStack);
            static void bellmanFord(ariel::Graph g, int s, vector<int> &distances);
            static bool hasLoopbacks(ariel::Graph g);
            static int minDistance(vector<int> distances, vector<bool> visited);
            
        public:
            Algorithms();
            static bool isConnected(ariel::Graph g);
            static string shortestPath(ariel::Graph g, int s, int e);
            static bool isContainsCycle(ariel::Graph g);
            static string isBipartite(ariel::Graph g);
            static string negativeCycle(ariel::Graph g);
    };
}

#endif