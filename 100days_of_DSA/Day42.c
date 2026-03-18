//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }
    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}
