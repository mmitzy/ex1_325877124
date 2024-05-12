#include "Graph.hpp"
#include <iostream>
using namespace std;

using namespace ariel;

    Graph::Graph() : edges_count(0), vertices_count(0){
        std::vector<std::vector<int>> curr_graph;
    }

    void Graph::loadGraph(std::vector<std::vector<int>> givenGraph){
        if(givenGraph.empty()){
            throw invalid_argument("The graph is empty");
        }
        if(givenGraph.size() != givenGraph[0].size()){
            throw invalid_argument("The graph is not a square matrix");
        }

        this->curr_graph = givenGraph;
        this->vertices_count = givenGraph.size();
        int found_edges = 0;
        for(vector<int>::size_type i=0; i < vertices_count; i++){
            for(vector<int>::size_type j=0; j < vertices_count; j++){
                curr_graph[i][j] = givenGraph[i][j];
                if(curr_graph[i][j] != 0){
                    found_edges++;
                }
            }
        }
        this->edges_count = found_edges;

    }

    void Graph::printGraph(){
        vector<int>::size_type i=0, j=0;
        for(i=0; i < vertices_count-1; i++){
            cout << "{";
            for(j=0; j < vertices_count-1; j++){
                cout << curr_graph[i][j] << ", ";
            }
            cout << curr_graph[i][j+1];
            cout << "}," << endl;
        }
        cout << "}" << endl;
    }

    vector<int>::size_type Graph::getEdgesCount(){
        return (vector<int>::size_type)edges_count;
    }

    vector<int>::size_type Graph::getVerticesCount(){
        return (vector<int>::size_type)vertices_count;
    }

    int Graph::getGraphValue(int i, int j){
        return (int)curr_graph[(vector<int>::size_type)i][(vector<int>::size_type)j];
    }
