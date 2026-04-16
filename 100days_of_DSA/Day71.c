//Problem Statement:Implement a hash table using quadratic probing with formula::h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int table[100];

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hash(key, m) + i * i) % m;
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hash(key, m) + i * i) % m;
        if (table[index] == EMPTY) {
            return 0;
        }
        if (table[index] == key) {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
