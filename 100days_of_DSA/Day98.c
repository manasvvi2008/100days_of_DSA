//Problem: Given intervals, merge all overlapping ones.
//Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int cmpEnd(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmpStart);

    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        qsort(heap, size, sizeof(int), cmpEnd);

        if (heap[0] <= arr[i].start) {
            heap[0] = arr[i].end;
        } else {
            heap[size++] = arr[i].end;
        }
    }

    printf("%d\n", size);

    free(heap);
    return 0;
}
