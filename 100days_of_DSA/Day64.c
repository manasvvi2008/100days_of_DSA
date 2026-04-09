//Perform BFS from a given source using queue.
#include <stdio.h>
#include <stdlib.h>

int queue[1000], front = 0, rear = 0;
int visited[1000];

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, s;
    scanf("%d", &n);

    int **adj = malloc(n * sizeof(int *));
    int *sizes = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        adj[i] = malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < sizes[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
        }
    }

    return 0;
}
