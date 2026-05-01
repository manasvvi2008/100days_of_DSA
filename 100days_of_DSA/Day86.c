//Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as 
//the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            ans = mid;
            break;
        } else if (sq < n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
