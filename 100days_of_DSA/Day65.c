// Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

int **adj, *sizes, *visited;

int dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < sizes[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, v)) return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    adj = malloc(n * sizeof(int *));
    sizes = malloc(n * sizeof(int));
    visited = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        adj[i] = malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) printf("YES");
    else printf("NO");

    return 0;
}
