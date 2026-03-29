//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed 
//together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* left = lca(root->left, n1, n2);
    struct Node* right = lca(root->right, n1, n2);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* res = lca(root, a, b);
    if (res) printf("%d", res->data);

    free(arr);
    return 0;
}
