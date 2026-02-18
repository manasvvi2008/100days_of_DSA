//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] != 1) ok = false;
            } else {
                if(a[i][j] != 0) ok = false;
            }
        }
    }

    if(ok) cout << "Yes";
    else cout << "No";

    return 0;
}
