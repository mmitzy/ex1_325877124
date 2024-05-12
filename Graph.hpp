#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph{
        private:
            int edges_count;
            int vertices_count;
            vector<vector<int>> curr_graph;

        public:
            Graph();
            void loadGraph(std::vector<std::vector<int>> graph);
            void printGraph();
            vector<int>::size_type getEdgesCount();
            vector<int>::size_type getVerticesCount();
            int getGraphValue(int i, int j);

    };
}

#endif