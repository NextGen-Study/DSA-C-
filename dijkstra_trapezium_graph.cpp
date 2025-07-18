
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>

using namespace std;

typedef unordered_map<int, vector<pair<int, int>>> Graph;

void dijkstra(Graph& graph, int source, int n) {
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty()) {
        auto top = *(s.begin());
        s.erase(s.begin());

        int node = top.second;
        int nodeDist = top.first;

        for (auto neighbor : graph[node]) {
            int adjNode = neighbor.first;
            int weight = neighbor.second;

            if (nodeDist + weight < dist[adjNode]) {
                auto it = s.find({dist[adjNode], adjNode});
                if (it != s.end()) {
                    s.erase(it);
                }

                dist[adjNode] = nodeDist + weight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }

// while (!s.empty()) {
//     // Get the node with the smallest distance
//     pair<int, int> current = *s.begin();
//     s.erase(s.begin());

//     int currentNode = current.second;
//     int currentDistance = current.first;

//     // Traverse all adjacent nodes
//     vector<pair<int, int>> neighbors = graph[currentNode];
//     for (int i = 0; i < neighbors.size(); ++i) {
//         int neighbor = neighbors[i].first;
//         int weight = neighbors[i].second;

//         int newDistance = currentDistance + weight;

//         // If a shorter path is found
//         if (newDistance < dist[neighbor]) {
//             pair<int, int> oldEntry = {dist[neighbor], neighbor};
//             set<pair<int, int>>::iterator it = s.find(oldEntry);
//             if (it != s.end()) {
//                 s.erase(it);
//             }

//             dist[neighbor] = newDistance;
//             s.insert({newDistance, neighbor});
//         }
//     }
// }




    cout << "Shortest distances from node " << source << ":";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }
}

int main() {
    Graph graph;

    // Adding edges (undirected)
    graph[0].push_back({1, 5});
    graph[1].push_back({0, 5});

    graph[0].push_back({2, 8});
    graph[2].push_back({0, 8});

    graph[1].push_back({2, 9});
    graph[2].push_back({1, 9});

    graph[1].push_back({3, 2});
    graph[3].push_back({1, 2});

    graph[3].push_back({2, 6});
    graph[2].push_back({3, 6});

    int n = 4;       // 4 nodes: 0 to 3
    int source = 0;  // Start from node 0

    dijkstra(graph, source, n);

    return 0;
}
