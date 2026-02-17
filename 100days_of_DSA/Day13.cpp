// You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    vector<int> result;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            result.push_back(matrix[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result.push_back(matrix[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    for (int x : result)
        cout << x << " ";

    return 0;
}
