//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. 
//In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][101];
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    int count[1000] = {0};

    for (int i = 0; i < n; i++) {
        if (count[i] != -1) {
            count[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(names[i], names[j]) == 0) {
                    count[i]++;
                    count[j] = -1;
                }
            }
        }
    }

    int max = 0;
    char winner[101] = "";

    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            if (count[i] > max || (count[i] == max && strcmp(names[i], winner) < 0)) {
                max = count[i];
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, max);
    return 0;
}
