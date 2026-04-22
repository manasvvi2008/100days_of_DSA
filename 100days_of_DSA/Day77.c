//using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>
#include <stdlib.h>

int **adj;
int *visited;

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)calloc(n + 1, sizeof(int));
    }

    visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1, n);

    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");

    for (int i = 0; i <= n; i++) free(adj[i]);
    free(adj);
    free(visited);

    return 0;
}
