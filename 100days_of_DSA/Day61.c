//Build a graph with n vertices and m edges using adjacency matrix representation.The graph may be directed or undirected.
#include <stdio.h>

#define MAX 100  // Maximum number of vertices

int main() {
    int n, m;
    int adj[MAX][MAX] = {0}; // Initialize adjacency matrix with 0
    int i, u, v;
    int isDirected;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Ask user if graph is directed or undirected
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &isDirected);

    // Input edges
    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Set edge in adjacency matrix
        adj[u][v] = 1;

        // If undirected, also set reverse edge
        if (!isDirected) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
