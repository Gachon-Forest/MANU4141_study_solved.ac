/*
Date: 8/1
No: 1697
Tier: s - 1
Name: ¼û¹Ú²ÀÁú 
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int visited[MAX] = {0};
int queue[MAX];
int front = 0, back = 0;

void enqueue(int position)
{
    queue[back++] = position;
}

int dequeue()
{
    return queue[front++];
}

int bfs(int N, int K)
{
    enqueue(N);
    visited[N] = 1;

    while (front < back)
    {
        int current = dequeue();

        if (current == K)
        {
            return visited[current] - 1;
        }
        int next_positions[3] = {current - 1, current + 1, current * 2};

        for (int i = 0; i < 3; i++) 
        {
            int next = next_positions[i];

            if (next >= 0 && next < MAX && visited[next] == 0) 
            {
                visited[next] = visited[current] + 1;
                enqueue(next);
            }
        }
    }
    return -1;
}

int main()
{
    int N, K;
   
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs(N, K));

    return 0;
}