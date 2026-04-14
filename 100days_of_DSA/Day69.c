//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

int minDistance() {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int edges, u, v, w, src;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    scanf("%d", &src);

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
