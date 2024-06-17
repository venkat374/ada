//p6 dijktras algo

#include <stdio.h>

#define MAX 10
#define INF 999

int n, cost[MAX][MAX], dist[MAX];

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

void read_mat(int n) 
{
    int i, j;
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
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
}

void shortestpath(int n, int s) 
{
    int vis[MAX], c, u, i, k;
    for (i = 1; i <= n; i++) 
    {
        vis[i] = 0;
        dist[i] = cost[s][i];
    }
    dist[s] = 0;
    vis[s] = 1;

    for (k = 1; k <= n - 1; k++) 
    {  
        c = INF;
        for (i = 1; i <= n; i++) 
        {
            if (vis[i] == 0 && dist[i] < c) 
            {
                c = dist[i];
                u = i;
            }
        }
        vis[u] = 1;

        for (i = 1; i <= n; i++) 
        {
            if (vis[i] == 0) 
            {
                dist[i] = min(dist[i], dist[u] + cost[u][i]);
            }
        }
    }
}

int main() 
{
    int i, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    read_mat(n);
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    shortestpath(n, s);
    printf("The shortest path from vertex %d to:\n", s);
    for (i = 1; i <= n; i++) 
    {
        printf("Vertex %d is %d\n", i, dist[i]);
    }
    return 0;
}
