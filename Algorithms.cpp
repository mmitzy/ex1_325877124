
#include "Algorithms.hpp"
#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using namespace ariel;


    Algorithms::Algorithms(){
        curr_graph = vector<vector<int>>();
    }


    bool Algorithms::dfs(Graph g, int s, vector<bool> &visited, vector<bool> &recStack){
        vector<int>::size_type start = (vector<int>::size_type)s;
        if (visited[start] == false){
            visited[start] = true;
            recStack[start] = true;
            for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
                if(g.getGraphValue(start, i) != 0 && !visited[i] && dfs(g, i, visited, recStack)){
                    return true;
                }
                else if(recStack[i]){
                    return true;
                }
            }
        }
        return false;
    }

    void Algorithms::bellmanFord(Graph g, int s, vector<int> &distances){ 
        vector<int>::size_type start = (vector<int>::size_type)s;
        distances[start] = 0;
        for(vector<int>::size_type i=0; i < g.getVerticesCount() - 1; i++){
            for(vector<int>::size_type j=0; j < g.getEdgesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    distances[j] = distances[i] + g.getGraphValue(i, j);
                }
            }
        }
    }
    
    bool Algorithms::hasLoopbacks(Graph g){
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(i, i) != 0){
                return true;
            }
        }

        return false;
    }

    int Algorithms::minDistance(vector<int> distances, vector<bool> visited){
        int min = INT32_MAX;
        int min_index = -1;

        for(vector<int>::size_type i=0; i < distances.size(); i++){
            if(!visited[i] && distances[i] <= min){
                min = distances[i];
                min_index = i;
            }
        }

        return min_index;
    }


    bool Algorithms::isConnected(Graph g){
        vector<bool> visited = vector<bool>(g.getVerticesCount(), false);
        vector<bool> recStack = vector<bool>(g.getVerticesCount(), false);
        dfs(g, 0, visited, recStack);
        for(vector<bool>::size_type i=0; i < g.getVerticesCount(); i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    string Algorithms::shortestPath(Graph g, int s, int e){
        vector<int>::size_type start = (vector<int>::size_type)s;
        vector<int>::size_type end = (vector<int>::size_type)e;
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX); 
        vector<bool> included_stp = vector<bool>(g.getVerticesCount(), false);
        distances[start] = 0;

        for(vector<bool>::size_type i=0; i < g.getVerticesCount() - 1; i++){
            vector<int>::size_type u = (vector<int>::size_type)minDistance(distances, included_stp);
            included_stp[u] = true;

            for(vector<int>::size_type j=0; j < g.getVerticesCount(); j++){
                if(g.getGraphValue(u, j) != 0 && !included_stp[j] && distances[u] != INT32_MAX && distances[j] > distances[u] + g.getGraphValue(u, j)){
                    distances[j] = distances[u] + g.getGraphValue(u, j);
                }
            }
        }

        string ans ="";
        bool first = true;
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(distances[i] == INT32_MAX){
                return "-1";
            }
            else if(first){
                ans += (to_string(distances[i]));
                first = false;
            }
            else{
                ans += ("->" + to_string(distances[i]));

            }
        }

        return ans;
    }


    bool Algorithms::isContainsCycle(Graph g){
        vector<bool> visited = vector<bool>(g.getVerticesCount(), false);
        vector<bool> recStack = vector<bool>(g.getVerticesCount(), false);
        for(vector<bool>::size_type i=0; i < g.getVerticesCount(); i++){
            if(!visited[i] && dfs(g, i, visited, recStack)){
                return true;
            }
        }

        return false;
    }

    string Algorithms::isBipartite(Graph g){
        if(hasLoopbacks(g)){
            return "The graph is not bipartite";
        }
        vector<int> color = vector<int>(g.getVerticesCount(), -1);
        color[0] = 1;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            vector<int>::size_type curr = (vector<int>::size_type)q.front();
            q.pop();

            for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
                if(g.getGraphValue(curr, i) != 0){
                    if(color[i] == -1){
                        color[i] = 1 - color[curr];
                        q.push(i);
                    }       
                    else if(g.getGraphValue(curr, i) && color[i] == color[curr]){ 
                        return "0";
                    }
                }
            }
        }

        string ans = "The graph is bipartite: A={";
        bool first = true;
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(color[i] == 1){
                if(first){
                    ans += to_string(i);
                    first = false;
                }
                else{
                    ans += ", " + to_string(i);
                }
            }
        }
        ans += "}, B={";
        first = true;
        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            if(color[i] == 0){
                if(first){
                    ans += to_string(i);
                    first = false;
                }
                else{
                    ans += ", " + to_string(i);
                }
            }
        }
        ans += "}";

        return ans;
    }

    string Algorithms::negativeCycle(Graph g){
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX);
        bellmanFord(g, 0, distances);

        for(vector<int>::size_type i=0; i < g.getVerticesCount(); i++){
            for(vector<int>::size_type j=0; j < g.getVerticesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    return "The graph contains a negative cycle";
                    
                }
            }
        }

        return "The graph does not have a negative cycle";
    }

    



