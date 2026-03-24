// Count Leaf Nodes
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

typedef struct Queue {
    Node** arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (Node**)malloc(capacity * sizeof(Node*));
    return q;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, Node* item) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = item;
    q->size++;
}

Node* dequeue(Queue* q) {
    Node* item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int countLeaves(Node* root) {
    if (!root) return 0;
    Queue* q = createQueue(1000);
    enqueue(q, root);
    int count = 0;
    while (!isEmpty(q)) {
        Node* temp = dequeue(q);
        if (!temp->left && !temp->right) count++;
        if (temp->left) enqueue(q, temp->left);
        if (temp->right) enqueue(q, temp->right);
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }

    int val;
    scanf("%d", &val);
    Node* root = createNode(val);

    Queue* q = createQueue(1000);
    enqueue(q, root);

    int count = 1;

    while (count < n) {
        Node* curr = dequeue(q);

        int l, r;

        if (count < n) {
            scanf("%d", &l);
            count++;
            if (l != -1) {
                curr->left = createNode(l);
                enqueue(q, curr->left);
            }
        }

        if (count < n) {
            scanf("%d", &r);
            count++;
            if (r != -1) {
                curr->right = createNode(r);
                enqueue(q, curr->right);
            }
        }
    }

    printf("%d", countLeaves(root));
    return 0;
}
