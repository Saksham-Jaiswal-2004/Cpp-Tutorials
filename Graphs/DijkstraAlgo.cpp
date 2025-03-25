#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cstdlib>
#include<ctime>

using namespace std;

// Function to implement Dijkstra's Algorithm
void dijkstra(int src, int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int V = rand() % 10 + 5; // Random number of vertices (5 to 14)
    int E = rand() % (V * (V - 1) / 2) + V; // Random number of edges (at least V)

    vector<pair<int, int>> adj[V];
    cout << "Randomized Graph with " << V << " vertices and " << E << " edges:\n";

    for (int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        int w = rand() % 20 + 1; // Random weight (1 to 20)

        if (u != v) { // Avoid self-loops
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Remove this line for directed graphs
            cout << "Edge: " << u << " - " << v << " with weight " << w << "\n";
        }
    }

    int src = rand() % V; // Random source vertex
    cout << "Randomized Source Vertex: " << src << "\n";

    dijkstra(src, V, adj);

    return 0;
}