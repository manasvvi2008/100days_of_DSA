//Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int postIndex;

// Create node
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
struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[postIndex--];
    struct TreeNode* root = newNode(rootVal);

    int mid = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANT: right first
    root->right = build(inorder, postorder, mid + 1, inEnd);
    root->left  = build(inorder, postorder, inStart, mid - 1);

    return root;
}

// Print preorder
void printPreorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1);

    printPreorder(root);

    free(inorder);
    free(postorder);

    return 0;
}
