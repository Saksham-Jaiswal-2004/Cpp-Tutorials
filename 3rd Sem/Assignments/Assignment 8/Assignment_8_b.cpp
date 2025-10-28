#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

// Function to build adjacency list from edge list
vector<vector<pair<int, int>>> buildAdjList(int V, const vector<Edge> &edges)
{
    vector<vector<pair<int, int>>> adj(V);
    for (auto &e : edges)
    {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w}); // undirected
    }
    return adj;
}

// Prim's Algorithm
int primMST(int V, const vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(V, INT_MAX);  // Minimum edge weight to connect vertex
    vector<int> parent(V, -1);    // Parent vertex in MST
    vector<bool> inMST(V, false); // Track vertices included in MST

    // Min-heap {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0; // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue; // Skip if already added
        inMST[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in the Minimum Spanning Tree (Prim’s):\n";
    for (int i = 1; i < V; ++i)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " -- " << i << "  (Cost: " << key[i] << ")\n";
            totalCost += key[i];
        }
    }

    cout << "\nTotal Minimum Cost of Wiring (Prim’s): " << totalCost << "\n";
    return totalCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 10; // number of houses
    vector<Edge> edges;

    // Randomly generate same type of partially connected graph as before
    srand(time(0));
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (rand() % 3 == 0)
            { // 1/3 probability of edge
                int w = rand() % 100 + 1;
                edges.push_back({i, j, w});
            }
        }
    }

    cout << "Number of houses (vertices): " << V << "\n";
    cout << "Number of possible connections (edges): " << edges.size() << "\n\n";

    auto adj = buildAdjList(V, edges);

    int totalCost = primMST(V, adj);

    cout << "\n--- Time Complexity Comparison ---\n";
    cout << "Prim's Algorithm: O(E + V log V)\n";
    cout << "Kruskal's Algorithm: O(E log E)\n";
    cout << "Prim’s is usually better for dense graphs, while Kruskal’s suits sparse graphs.\n";

    return 0;
}
