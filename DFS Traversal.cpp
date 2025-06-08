#include <iostream>
#include <map>
#include <list>
using namespace std;

// DFS function
void dfs(map<int, list<int>> &adj, map<int, bool> &visited, int node) {
    visited[node] = true;
    cout << node << " ";

    // Convert list to array to avoid using iterator
    list<int> neighbors = adj[node];
    int arr[100], k = 0;

    for (int val : neighbors) {
        arr[k++] = val;
    }

    for (int i = 0; i < k; i++) {
        int neighbour = arr[i];
        if (!visited[neighbour]) {
            dfs(adj, visited, neighbour);
        }
    }
}

int main() {
    map<int, list<int>> adj;
    map<int, bool> visited;

    // Graph edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);

    cout << "DFS starting from node 0: ";
    dfs(adj, visited, 0);

    return 0;
}
