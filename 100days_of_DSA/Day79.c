//Find shortest distances from source vertex in a weighted graph with non-negative weights.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

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

    int source;
    scanf("%d", &source);

    int *dist = (int*)malloc((n + 1) * sizeof(int));
    int *visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    for (int i = 0; i <= n; i++) free(graph[i]);
    free(graph);
    free(dist);
    free(visited);

    return 0;
}
