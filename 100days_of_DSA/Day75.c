//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int *hash = (int*)malloc((2 * n + 1) * sizeof(int));
    for (int i = 0; i < 2 * n + 1; i++) hash[i] = -2;

    int sum = 0, maxLen = 0, offset = n;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) maxLen = i + 1;

        if (hash[sum + offset] == -2)
            hash[sum + offset] = i;
        else {
            int len = i - hash[sum + offset];
            if (len > maxLen) maxLen = len;
        }
    }

    printf("%d\n", maxLen);

    free(arr);
    free(hash);
    return 0;
}
