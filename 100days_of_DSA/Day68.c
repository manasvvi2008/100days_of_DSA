//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int main() {
    int n, edges;
    int front = 0, rear = -1;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while (front <= rear) {
        int u = queue[front++];
        printf("%d ", u);

        for (int i = 0; i < n; i++) {
            if (graph[u][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    return 0;
}
