#include <iostream>
#include <map>
#include <list>
using namespace std;

// DFS function
void dfs(map<int, list<int>> &graph, map<int, bool> &visited, int node) {
    visited[node] = true;
    cout << node << " ";

    list<int> neighbors = graph[node];

    for (int val : neighbors) {
    
        if (!visited[val]) {
            dfs(graph, visited, val);
        }
    }
}

int main() {
    map<int, list<int>> graph;
    map<int, bool> visited;

    // Graph edges
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[3].push_back(4);

    cout << "DFS starting from node 0: ";
    dfs(graph, visited, 0);

    return 0;
}
