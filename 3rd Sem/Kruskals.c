// 1. Sort all edges according to weight
#include <stdio.h>
#include <stdlib.h>

struct Edge 
{
    int u, v, w;
};

int cmp(const void *a, const void *b) 
{
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int find(int parent[], int x) 
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]); // Path compression
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) 
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) 
    {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else 
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void Kruskal(struct Edge edges[], int V, int E) 
{
    qsort(edges, E, sizeof(edges[0]), cmp);

    int parent[V], rank[V];
    for (int i = 0; i < V; i++) 
    {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edges in MST using Kruskal:\n");
    int count = 0;
    for (int i = 0; i < E && count < V-1; i++) 
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(parent, u) != find(parent, v)) 
        {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            unionSet(parent, rank, u, v);
            count++;
        }
    }
}

int main() 
{
    int V = 4, E = 5;
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    Kruskal(edges, V, E);
    return 0;
}