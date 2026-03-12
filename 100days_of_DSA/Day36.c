// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int n, m, x;
    scanf("%d", &n);

    Node *front = NULL, *rear = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = x;
        if (front == NULL) {
            front = rear = temp;
            temp->next = front;
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (front != NULL) {
            front = front->next;
            rear = rear->next;
        }
    }

    if (front != NULL) {
        Node* temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }

    return 0;
}
