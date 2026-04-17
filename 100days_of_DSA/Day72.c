//Problem Statement:Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it 
//appears more than once,and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    scanf("%s", s);

    for (int i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
