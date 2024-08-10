/*
Date: 7/28
No: 2606
Tier: s - 3
Name: 바이러스
Language: C 99
*/

#include <stdio.h>

#define MAX_NODES 105

int graph[MAX_NODES][MAX_NODES] = {0};
int virus[MAX_NODES] = {0};
int ans = 0;

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) 
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    virus[1] = 1;
    ans++;

    int to_visit[MAX_NODES];
    int visit_start = 0, visit_end = 0;

    to_visit[visit_end++] = 1;

    while (visit_start < visit_end)
    {
        int node = to_visit[visit_start++];

        for (int i = 1; i <= n; i++) 
        {
            if (graph[node][i] && virus[i] == 0) 
            {
                virus[i] = 1;
                ans++;
                to_visit[visit_end++] = i;
            }
        }
    }

    printf("%d\n", ans - 1);  

    return 0;
}