/* Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order. */
#include <iostream>
using namespace std;
int main() {
    int n;
    int a[100];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }
    for(int i = 0; i <= j; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
