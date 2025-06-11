#include <iostream>
#include <map>
#include <list>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

// Function to find the vertex with minimum key value not yet included in MST
int minKey(int key[], bool inMST[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (!inMST[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST(map<int, list<pair<int, int>>> &graph, int start) {
    int key[V];      // Minimum weight to reach each vertex
    bool inMST[V];   // True if vertex is included in MST
    int parent[V];   // To store constructed MST

    // Step 1: Initialize all keys as INFINITE and inMST[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[start] = 0; // Start from the given vertex

    // Step 2: Repeat for V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST);  // Pick minimum key vertex not in MST
        inMST[u] = true;             // Include u in MST

        // Step 3: Update key and parent of adjacent vertices
        for (auto &nbr : graph[u]) {
            int v = nbr.first;
            int weight = nbr.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // Step 4: Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
    }
}

int main() {
    map<int, list<pair<int, int>>> graph;

    // Undirected weighted graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});

    primMST(graph, 0);

    return 0;
}
