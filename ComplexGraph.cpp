#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Function to add an edge to the graph
void addEdge(map<int, vector<int>> &adj, int u, int v) {
    adj[u].push_back(v); // Add v to u's list
    adj[v].push_back(u); // Add u to v's list (undirected graph)
}

// Function to print the graph
void printGraph(map<int, vector<int>> &adj) {
    for (auto i : adj) {
        cout << "Vertex " << i.first << ": ";
        for (int neighbor : i.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    map<int, vector<int>> adj; // Adjacency list using map

    // Adding edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Print the graph
    printGraph(adj);

    return 0;
}
