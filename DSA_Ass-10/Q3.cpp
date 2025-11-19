#include <iostream>
#include <vector>
using namespace std;

// DFS function (recursive)
void DFS(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;
    cout << node << " ";

    // Visit all unvisited neighbors
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, visited, adj);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Remove this line for directed graph
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFS(start, visited, adj);

    cout << endl;
    return 0;
}
