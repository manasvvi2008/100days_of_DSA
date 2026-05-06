//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
#include <stdio.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int canPaint(int arr[], int n, int k, long long maxTime) {
    int painters = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return 0;

        if (sum + arr[i] > maxTime) {
            painters++;
            sum = arr[i];
            if (painters > k) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    long long total = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
        mx = max(mx, arr[i]);
    }

    long long left = mx, right = total, ans = total;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
