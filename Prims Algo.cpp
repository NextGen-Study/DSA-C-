#include <iostream>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

void primMST(int graph[V][V]) {
    int parent[V];    // Stores MST
    int key[V];       // Minimum weight edge to each vertex
    bool visited[V];  // True if vertex is included in MST

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }
                                                 
    key[0] = 0;        // Start from vertex 0
    parent[0] = -1;    // First node is root, so no parent

    // Construct MST with V-1 edges
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        // Find the unvisited vertex with the smallest key
        for (int v = 0; v < V; v++)
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }

        visited[u] = true; // Include u in MST

        // Update adjacent vertices of u
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    // Print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}