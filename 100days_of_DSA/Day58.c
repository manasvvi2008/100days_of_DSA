//Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int preIndex = 0;

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct TreeNode* root = newNode(rootVal);

    int mid = findIndex(inorder, inStart, inEnd, rootVal);

    root->left = build(preorder, inorder, inStart, mid - 1);
    root->right = build(preorder, inorder, mid + 1, inEnd);

    return root;
}

// Print postorder
void printPostorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct TreeNode* root = build(preorder, inorder, 0, n - 1);

    printPostorder(root);

    free(preorder);
    free(inorder);

    return 0;
}
