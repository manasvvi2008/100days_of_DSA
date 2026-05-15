//Problem: For each element, count how many smaller elements appear on right side.
//Use merge sort technique or Fenwick Tree (BIT).
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pair *L = (Pair*)malloc(n1 * sizeof(Pair));
    Pair *R = (Pair*)malloc(n2 * sizeof(Pair));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left, rightCount = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].idx] += rightCount;
            arr[k++] = L[i++];
        } else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].idx] += rightCount;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Pair *arr = (Pair*)malloc(n * sizeof(Pair));
    int *count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    free(arr);
    free(count);

    return 0;
}
