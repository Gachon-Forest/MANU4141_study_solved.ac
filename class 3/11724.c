/*
Date: 8/6
No: 11724
Tier: s - 2
Name: 연결 요소의 개수
Language: C 99
*/

#include <stdio.h>

int n, arr[1001][1001], visit[1001];

void DFS(int start) 
{
    visit[start] = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (arr[start][i] && !visit[i]) 
        {
            DFS(i);
        }
    }
}

int main() 
{
    int m, a, b, cnt = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            arr[i][j] = 0;
        }
        visit[i] = 0;
    }

    for (int i = 1; i <= m; i++) 
    {
        scanf("%d %d", &a, &b);
        arr[a][b] = arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) 
    {
        if (!visit[i]) 
        {
            DFS(i);
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}