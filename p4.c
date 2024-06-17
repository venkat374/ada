//p4 prims algo

#include <stdio.h>

#define INF 999

int main() 
{
    int n, i, j, u, v, ne = 1;
    int min, mincost = 0, cost[10][10];
    int visited[10] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++) 
        {
            printf("(%d, %d): ", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) 
            {
                cost[i][j] = INF;  // Set to a large value to denote no connection
            }
        }
    }

    visited[1] = 1;  // Start from the first vertex
    printf("The edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) 
    {
        min = INF;

        for (i = 1; i <= n; i++) 
        {
            if (visited[i]) 
            {
                for (j = 1; j <= n; j++) 
                {
                    if (!visited[j] && cost[i][j] < min) 
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (!visited[v]) 
        {
            printf("%d edge (%d, %d) = %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = INF;  // Remove the edge from consideration
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}