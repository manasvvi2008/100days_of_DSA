//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if(i == j) sum += x;
        }
    }

    cout << sum;
    return 0;
}
