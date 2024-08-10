/*
Date: 8/9
No: 14940
Tier: s - 1
Name: 쉬운 최단거리
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue {
    int y;
    int x;
} Queue;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

Queue* q;
int n, m;

void BFS(int** map, int** visited, int fy, int fx);

int main()
{
    scanf("%d %d", &n, &m);

    int** map = (int**)calloc(n, sizeof(int*));
    int** visited = (int**)calloc(n, sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        map[i] = (int*)calloc(m, sizeof(int));
        visited[i] = (int*)calloc(m, sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 2)
            {
                BFS(map, visited, i, j);
                visited[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(map[i]);
        free(visited[i]);
    }
    free(map);
    free(visited);

    return 0;
}

void BFS(int** map, int** visited, int fy, int fx)
{
    q = (Queue*)calloc(n * m, sizeof(Queue));
    int front = -1, back = 0;

    q[back].y = fy;
    q[back].x = fx;

    while (front < back)
    {
        front++;
        int order = visited[q[front].y][q[front].x];

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = q[front].y + dy[dir];
            int nx = q[front].x + dx[dir];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (!visited[ny][nx] && map[ny][nx])
                {
                    back++;
                    q[back].y = ny;
                    q[back].x = nx;
                    visited[ny][nx] = order + 1;
                }
            }
        }
    }
    free(q);
}