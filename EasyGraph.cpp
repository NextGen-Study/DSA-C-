#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V]; // Adjacency list of size V

    // Adding edges (Undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(3);
    adj[3].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    // Display adjacency list
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " is connected to: ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
