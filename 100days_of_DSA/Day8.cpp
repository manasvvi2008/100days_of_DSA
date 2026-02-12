//Given integers a and b, compute a^b using recursion without using pow() function.
#include <iostream>
using namespace std;
long long power(long long a, long long b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout << power(a, b);
    return 0;
}
