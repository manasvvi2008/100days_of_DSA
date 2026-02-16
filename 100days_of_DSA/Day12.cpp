// Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int a[100][100];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if(m != n) {
        cout << "Not a Symmetric Matrix";
        return 0;
    }
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                cout << "Not a Symmetric Matrix";
                return 0;
            }
        }
    }
    cout << "Symmetric Matrix";
    return 0;
}
