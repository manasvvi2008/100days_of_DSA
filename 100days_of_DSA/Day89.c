//Problem Statement:Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each 
//student gets at least one book and the maximum number of pages assigned to a student is minimized.
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;
        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
            if (students > m) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int total = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
        mx = max(mx, arr[i]);
    }

    int left = mx, right = total, ans = total;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
