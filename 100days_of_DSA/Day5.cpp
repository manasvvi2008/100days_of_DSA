//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
#include <iostream>
using namespace std;
int main() {
    int m, n;
    int a[100], b[100], c[200];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> a[i];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> b[i];
    int i = 0, j = 0, k = 0;
    while(i < m && j < n) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < m) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < n) {
        c[k] = b[j];
        j++;
        k++;
    }
    for(int x = 0; x < m + n; x++) {
        cout << c[x] << " ";
    }
    return 0;
}
