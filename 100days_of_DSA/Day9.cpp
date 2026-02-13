//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int i = 0, j = s.length() - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    cout << s;
    return 0;
}
