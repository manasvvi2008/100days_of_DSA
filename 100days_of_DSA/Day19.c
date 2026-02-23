// Given an array of integers, find two elements whose sum is closest to zero.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x = a[0], y = a[1];
    int best = x + y;
    if(best < 0) best = -best;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = a[i] + a[j];
            int absSum = sum;
            if(absSum < 0) absSum = -absSum;

            if(absSum < best)
            {
                best = absSum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d\n", x, y);
    return 0;
}

