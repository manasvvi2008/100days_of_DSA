//Given an array of integers, count the frequency of each distinct element and print the result.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];

    int visited[1000] = {0};

    for(int i = 0; i < n; i++) {
        if(visited[i] == 1) continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        cout << a[i] << " " << count << endl;
    }

    return 0;
}
