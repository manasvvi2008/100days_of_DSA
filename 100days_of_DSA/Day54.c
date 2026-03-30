//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = build(arr, n, 2*i+1);
    root->right = build(arr, n, 2*i+2);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = build(arr, n, 0);

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int *level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];
            int idx = leftToRight ? i : (size - 1 - i);
            level[idx] = node->data;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        free(level);
        leftToRight = !leftToRight;
    }

    free(arr);
    free(queue);
    return 0;
}
