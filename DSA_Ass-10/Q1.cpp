#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

// A simple Graph using adjacency list.
class Graph {
public:
    vector<vector<int>> adj; // adjacency list
    bool directed;

    Graph(bool directed = false) : directed(directed) {}

    // Ensure vertex index exists
    void ensureVertex(int v) {
        if (v >= (int)adj.size()) {
            adj.resize(v + 1);
        }
    }

    // Add edge u -> v
    void addEdge(int u, int v) {
        ensureVertex(max(u, v));

        // Avoid duplicates
        if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
            adj[u].push_back(v);
        }

        if (!directed) {
            if (find(adj[v].begin(), adj[v].end(), u) == adj[v].end()) {
                adj[v].push_back(u);
            }
        }
    }

    // Remove edge u -> v
    void removeEdge(int u, int v) {
        if (u < 0 || u >= (int)adj.size()) return;
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());

        if (!directed && v >= 0 && v < (int)adj.size()) {
            adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
        }
    }

    // Neighbors of v
    vector<int> neighbors(int v) {
        if (v < 0 || v >= (int)adj.size()) return {};
        vector<int> nb = adj[v];
        sort(nb.begin(), nb.end());
        return nb;
    }

    // Degrees
    int degree(int v) {
        return neighbors(v).size();
    }

    int outdegree(int v) {
        return degree(v);
    }

    int indegree(int v) {
        int cnt = 0;
        for (int u = 0; u < (int)adj.size(); u++) {
            for (int x : adj[u]) {
                if (x == v) cnt++;
            }
        }
        return cnt;
    }

    // Count edges
    int edgeCount() const {
        int total = 0;
        for (const auto& vec : adj) {
            total += vec.size();
        }
        return directed ? total : total / 2;
    }

    // Print adjacency list
    void print() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < (int)adj.size(); i++) {
            cout << i << ": ";
            if (adj[i].empty()) {
                cout << "(none)";
            } else {
                for (int v : adj[i]) {
                    cout << v << " ";
                }
            }
            cout << "\n";
        }
    }

    // Count vertices
    int vertexCount() const {
        return adj.size();
    }
};

// Utility: safely take an integer from user
int readInt(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        if (ss >> x) return x;
        cout << "Invalid number. Please try again.\n";
    }
}

int main() {
    cout << "Simple Graph Tool (C++ with <iostream>)\n";

    // Choose graph type
    cout << "Choose graph type:\n1) Directed\n2) Undirected\n";
    int type = readInt("Enter 1 or 2: ");
    bool directed = (type == 1);
    Graph G(directed);

    cout << (directed ? "Directed graph created.\n" : "Undirected graph created.\n");

    // Menu
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1) Add edge\n";
        cout << "2) Remove edge\n";
        cout << "3) Show neighbors\n";
        cout << "4) Degrees (degree/in/out)\n";
        cout << "5) Show graph info\n";
        cout << "6) Print adjacency list\n";
        cout << "0) Exit\n";

        int choice = readInt("Enter choice: ");

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }
        else if (choice == 1) {
            int u = readInt("From vertex: ");
            int v = readInt("To vertex: ");
            G.addEdge(u, v);
            cout << "Edge added.\n";
        }
        else if (choice == 2) {
            int u = readInt("From vertex: ");
            int v = readInt("To vertex: ");
            G.removeEdge(u, v);
            cout << "Edge removed.\n";
        }
        else if (choice == 3) {
            int v = readInt("Vertex: ");
            vector<int> nb = G.neighbors(v);
            cout << "Neighbors of " << v << ": ";
            if (nb.empty()) cout << "(none)";
            else for (int x : nb) cout << x << " ";
            cout << "\n";
        }
        else if (choice == 4) {
            int v = readInt("Vertex: ");
            if (directed) {
                cout << "In-degree: " << G.indegree(v) << "\n";
                cout << "Out-degree: " << G.outdegree(v) << "\n";
            } else {
                cout << "Degree: " << G.degree(v) << "\n";
            }
        }
        else if (choice == 5) {
            cout << "Vertices: " << G.vertexCount() << "\n";
            cout << "Edges: " << G.edgeCount() << "\n";
        }
        else if (choice == 6) {
            G.print();
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
