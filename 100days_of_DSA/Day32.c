//Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>
int main() {
    int n, m;

    scanf("%d", &n);

    int stack[100];  

    for(int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }

    int top = n - 1;  

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        if(top >= 0) {
            top--;  
        }
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
