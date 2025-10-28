#include <iostream>
#include <vector>

using namespace std;

// Check if current node can be added to the current independent set
bool isSafe(const vector<vector<int>> &graph, const vector<int> &currentSet, int node) 
{
    for (int v : currentSet) 
    {
        if (graph[v][node] == 1) // if edge exists, not safe
            return false;
    }
    return true;
}

// Recursive backtracking function
bool findIndependentSetUtil(const vector<vector<int>> &graph, int n, int k,vector<int> &currentSet, int start) 
{
    if ((int)currentSet.size() == k)
        return true;

    for (int i = start; i < n; i++) 
    {
        if (isSafe(graph, currentSet, i)) 
        {
            currentSet.push_back(i);
            if (findIndependentSetUtil(graph, n, k, currentSet, i + 1))
                return true;
            currentSet.pop_back();
        }
    }
    return false;
}

// Wrapper function
void findIndependentSet(const vector<vector<int>> &graph, int n, int k) 
{
    vector<int> currentSet;
    bool found = findIndependentSetUtil(graph, n, k, currentSet, 0);

    if (found) 
    {
        cout << "Independent Set of size " << k << " found: ";
        for (int v : currentSet)
            cout << v << " ";
        cout << endl;
    } 
    else 
    {
        cout << "No independent set of size " << k << " exists in this graph.\n";
    }
}

int main() 
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    findIndependentSet(graph, n, k);

    cout << "\n--- Time Complexity Analysis ---\n";
    cout << "Worst Case: O(C(n, k) * k) ≈ O(n^k)\n";
    cout << "Average Case: Much lower depending on edge density\n";
    cout << "Space Complexity: O(n^2) (for adjacency matrix) + O(k) recursion stack\n";

    return 0;
}