//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **graph = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) graph[i][j] = INT_MAX;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int *key = (int*)malloc((n + 1) * sizeof(int));
    int *mst = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) key[i] = INT_MAX;

    key[1] = 0;
    int total = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!mst[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        mst[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);

    for (int i = 0; i <= n; i++) free(graph[i]);
    free(graph);
    free(key);
    free(mst);

    return 0;
}
