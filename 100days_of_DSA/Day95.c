//Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
//Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->val >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next && curr->next->val < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float *arr = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);

    Node** buckets = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        insertSorted(&buckets[idx], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            arr[k++] = curr->val;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    for (int i = 0; i < n; i++) printf("%f ", arr[i]);

    free(arr);
    free(buckets);

    return 0;
}
