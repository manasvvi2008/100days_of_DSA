//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdlib.h>

int **adj, *sizes, *visited, *rec;

int dfs(int v) {
    visited[v] = 1;
    rec[v] = 1;

    for (int i = 0; i < sizes[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u)) return 1;
        } else if (rec[u]) {
            return 1;
        }
    }

    rec[v] = 0;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    adj = malloc(n * sizeof(int *));
    sizes = malloc(n * sizeof(int));
    visited = calloc(n, sizeof(int));
    rec = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        adj[i] = malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    return 0;
}
