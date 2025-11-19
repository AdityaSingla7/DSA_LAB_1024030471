#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A small struct to hold an edge
struct Edge {
    int u, v;
    int w;
};

// Disjoint Set Union (Union-Find) with path compression and union by rank
struct DSU {
    vector<int> parent;
    vector<int> rankv;

    DSU(int n) : parent(n), rankv(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    // find with path compression
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    // union by rank, returns true if union happened
    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        if (rankv[pa] < rankv[pb]) parent[pa] = pb;
        else if (rankv[pb] < rankv[pa]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rankv[pa]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Kruskal's Minimum Spanning Tree (MST)\n";
    int n, m;
    cout << "Enter number of vertices: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of vertices. Exiting.\n";
        return 0;
    }
    cout << "Enter number of edges: ";
    if (!(cin >> m) || m < 0) {
        cout << "Invalid number of edges. Exiting.\n";
        return 0;
    }

    vector<Edge> edges;
    cout << "Enter each edge as: u v w  (vertices are 0 to " << n-1 << ")\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Warning: edge (" << u << "," << v << ") ignored (vertex out of range).\n";
            continue;
        }
        edges.push_back({u, v, w});
    }

    // Sort edges by weight (ascending)
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    vector<Edge> mst;     // edges chosen for MST
    long long totalWeight = 0;

    // Kruskal's main loop
    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
            if ((int)mst.size() == n - 1) break; // MST complete
        }
    }

    // Check if MST spans all vertices
    if ((int)mst.size() != n - 1) {
        cout << "No spanning tree exists (graph is disconnected).\n";
    } else {
        cout << "\nEdges in the MST (u -- v : weight):\n";
        for (const auto &e : mst) {
            cout << e.u << " -- " << e.v << " : " << e.w << '\n';
        }
        cout << "Total weight of MST = " << totalWeight << '\n';
    }

    return 0;
}