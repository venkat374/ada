//p5 krushkals algo

#include<stdio.h>

void main()
{
    int n, v, u, cost[10][10], parent[10] = {0}, i, j;
    int count = 1, mincost = 0, min, a, b;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("(%d, %d): ", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Set to a large value to denote no connection
        }
    }

    while (count < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];

        if (u != v)
        {
            count++;
            printf("\nEdge (%d,%d) = %d", a, b, min);
            mincost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999; // Remove the edge from consideration
    } /* End of while */

    printf("\nMinimum cost = %d\n", mincost);
}
