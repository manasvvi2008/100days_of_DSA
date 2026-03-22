//Level Order Traversal
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
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

void levelOrder(Node* root) {
    if (!root) return;
    Queue* q = createQueue(1000);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* curr = dequeue(q);
        printf("%d ", curr->data);
        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) return 0;

    int val;
    scanf("%d", &val);
    Node* root = createNode(val);

    Queue* q = createQueue(1000);
    enqueue(q, root);

    int count = 1;

    while (count < n) {
        Node* curr = dequeue(q);

        int leftVal, rightVal;

        if (count < n) {
            scanf("%d", &leftVal);
            count++;
            if (leftVal != -1) {
                curr->left = createNode(leftVal);
                enqueue(q, curr->left);
            }
        }

        if (count < n) {
            scanf("%d", &rightVal);
            count++;
            if (rightVal != -1) {
                curr->right = createNode(rightVal);
                enqueue(q, curr->right);
            }
        }
    }

    levelOrder(root);
    return 0;
}
