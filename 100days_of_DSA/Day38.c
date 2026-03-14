//Deque (Double-Ended Queue)
//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    } else if (front > 0) {
        deque[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[rear] = x;
    } else if (rear < MAX - 1) {
        deque[++rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front++;
}

void pop_back() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else rear--;
}

int get_front() {
    if (isEmpty()) return -1;
    return deque[front];
}

int get_back() {
    if (isEmpty()) return -1;
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (isEmpty()) return;
    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sort_deque() {
    if (isEmpty()) return;
    qsort(deque + front, size(), sizeof(int), cmp);
}

void print_deque() {
    if (isEmpty()) return;
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sort_deque();
        } else if (strcmp(op, "print") == 0) {
            print_deque();
        }
    }
    return 0;
}
