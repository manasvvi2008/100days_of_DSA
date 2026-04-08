//Problem: Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    int visited[MAX];
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all as unvisited
    }
}

// Add edge (undirected by default)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS function (recursive)
void DFS(struct Graph* graph, int vertex) {
    // Mark current node as visited
    graph->visited[vertex] = 1;

    // Print the vertex
    printf("%d ", vertex);

    // Visit all adjacent vertices
    struct Node* temp = graph->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, start;

    struct Graph graph;

    // Input
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    initGraph(&graph, n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // DFS Traversal
    printf("DFS Traversal: ");
    DFS(&graph, start);

    printf("\n");

    return 0;
}
