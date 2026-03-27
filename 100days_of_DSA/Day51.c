//#include <stdio.h>
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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);
    return root;
}

int main() {
    int n, x, a, b;
    struct Node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &a, &b);
    struct Node* res = lca(root, a, b);
    if (res) printf("%d", res->data);
    return 0;
}
