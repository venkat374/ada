//p8 knapsack using dynamic programming method

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int max(int, int);

int v[10][10], w[10], p[10], x[10], count = 0;
int findobjects(int n, int m);

void main()
{
    int m, n, i, j;
    printf("Enter the number of objects\n");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack\n");
    scanf("%d", &m);
    printf("Enter the weights of the objects\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profits\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (i = 0; i <= n; i++) 
    {
        for (j = 0; j <= m; j++) 
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < w[i])
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], v[i-1][j-w[i]] + p[i]);
        }
    }
    printf("The output is:\n");
    for (i = 0; i <= n; i++) 
    {
        for (j = 0; j <= m; j++) 
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit is: %d\n", v[n][m]);
    findobjects(n, m);
    printf("Objects included in knapsack\n");
    for (i = 1; i <= count; i++)
        printf("%d\t", x[i]);
    printf("\n");
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int findobjects(int n, int m)
{
    int i, j;
    i = n;
    j = m;
    while (i != 0 && j != 0) 
    {
        if (v[i][j] != v[i-1][j]) 
        {
            x[++count] = i;
            m = m - w[i];
            j = m;
        }
        i--;
    }
    return 0;
}