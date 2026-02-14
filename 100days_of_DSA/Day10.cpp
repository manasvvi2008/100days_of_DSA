//Read a string and check if it is a palindrome using two-pointer comparison.
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            cout << "Not Palindrome";
            return 0;
        }
        i++;
        j--;
    }
    cout << "Palindrome";
    return 0;
}
