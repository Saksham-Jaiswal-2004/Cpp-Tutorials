#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) with path compression + union by rank
class DSU 
{
    vector<int> parent, rank;
public:
    DSU(int n) 
    {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) 
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) 
    {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

// Edge structure
struct Edge 
{
    int u, v, w;
    bool operator<(const Edge &other) const 
    {
        return w < other.w; // sort by weight
    }
};

// Kruskal’s Algorithm
int kruskalMST(int V, vector<Edge>& edges) 
{
    sort(edges.begin(), edges.end()); // Step 1: Sort edges
    DSU dsu(V);
    int mstCost = 0;
    vector<Edge> mstEdges;

    for (auto &e : edges) 
    {
        if (dsu.unite(e.u, e.v)) 
        { // Step 2: pick edge if no cycle
            mstCost += e.w;
            mstEdges.push_back(e);
        }
    }

    // Print MST edges
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto &e : mstEdges)
        cout << e.u << " -- " << e.v << "  (Cost: " << e.w << ")\n";

    cout << "\nTotal Minimum Cost of Wiring: " << mstCost << "\n";
    return mstCost;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 10; // number of houses (vertices)
    vector<Edge> edges;

    // Randomly generate a partially connected weighted undirected graph
    srand(time(0));
    for (int i = 0; i < V; i++) 
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (rand() % 3 == 0) 
            { // 1/3 probability of edge existing
                int w = rand() % 100 + 1; // weight between 1 and 100
                edges.push_back({i, j, w});
            }
        }
    }

    cout << "Number of houses (vertices): " << V << "\n";
    cout << "Number of possible connections (edges): " << edges.size() << "\n\n";

    int totalCost = kruskalMST(V, edges);

    cout << "\n--- Time Complexity Comparison ---\n";
    cout << "Kruskal's Algorithm: O(E log E)\n";
    cout << "Prim's Algorithm: O(E + V log V)\n";
    cout << "For sparse graphs (E < V^2/2), Kruskal’s is often faster.\n";

    return 0;
}