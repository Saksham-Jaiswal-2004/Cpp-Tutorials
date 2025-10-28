#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

// Randomly construct a partially complete undirected graph
vector<vector<int>> generateGraph(int N, double edgeProbability = 0.4) 
{
    vector<vector<int>> graph(N, vector<int>(N, 0));
    srand(time(0));

    for (int i = 0; i < N; i++) 
    {
        for (int j = i + 1; j < N; j++) 
        {
            if ((double)rand() / RAND_MAX < edgeProbability) 
            {
                graph[i][j] = graph[j][i] = 1;
            }
        }
    }
    return graph;
}

// Deterministic approach — O(N^2)
int countNonConnectedDeterministic(const vector<vector<int>> &graph) 
{
    int N = graph.size();
    int count = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = i + 1; j < N; j++) 
        {
            if (graph[i][j] == 0)
                count++;
        }
    }
    return count;
}

// Randomized approach — Random sampling
int countNonConnectedRandomized(const vector<vector<int>> &graph, int samples = 100) 
{
    int N = graph.size();
    int nonConnected = 0, totalChecked = 0;

    for (int s = 0; s < samples; s++) 
    {
        int i = rand() % N;
        int j = rand() % N;
        if (i != j) 
        {
            totalChecked++;
            if (graph[i][j] == 0)
                nonConnected++;
        }
    }

    // Estimate based on total possible edges (N*(N-1)/2)
    int totalEdges = N * (N - 1) / 2;
    double ratio = (double)nonConnected / totalChecked;
    return (int)(ratio * totalEdges);
}

void printGraph(const vector<vector<int>> &graph) 
{
    cout << "\nAdjacency Matrix:\n";
    for (auto &row : graph) 
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() 
{
    int N = 10;
    double edgeProbability = 0.4; // Adjust for density

    cout << "Randomly constructing a partially complete undirected graph (N=" << N << ")\n";
    vector<vector<int>> graph = generateGraph(N, edgeProbability);
    printGraph(graph);

    // Deterministic approach
    auto start1 = chrono::high_resolution_clock::now();
    int detCount = countNonConnectedDeterministic(graph);
    auto end1 = chrono::high_resolution_clock::now();

    // Randomized approach
    auto start2 = chrono::high_resolution_clock::now();
    int randCount = countNonConnectedRandomized(graph, 200); // 200 samples
    auto end2 = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> detTime = end1 - start1;
    chrono::duration<double, milli> randTime = end2 - start2;

    cout << "\n--------------------------------------------";
    cout << "\nDeterministic Non-Connected Edges: " << detCount;
    cout << "\nRandomized Estimated Non-Connected Edges: " << randCount;
    cout << "\n--------------------------------------------";
    cout << "\nDeterministic Time: " << detTime.count() << " ms";
    cout << "\nRandomized Time: " << randTime.count() << " ms";

    cout << "\n\n--- Time Complexity Analysis ---\n";
    cout << "Deterministic: O(N^2)\n";
    cout << "Randomized: O(k)  (k = number of random samples)\n";
    cout << "Average Case: Randomized is faster for large N\n";
    cout << "Worst Case: Both can take O(N^2) if all edges are checked.\n";

    return 0;
}