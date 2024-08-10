/*
Date: 8/5
No: 2630
Tier: s - 2
Name: 색종이 만들기
Language: C 99
*/

#include <stdio.h>

int paper[128][128], w, b;       

void color(int x, int y, int n) 
{
    int W = 0, B = 0;          

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++) 
        {
            if (paper[i][j] == 0) W++;
           
            else B++;
        }
    }

    if (W == n * n) w++;
    
    else if (B == n * n) b++;
        
    else 
    {
        int half = n / 2;
        color(x, y, half);
        color(x, y + half, half);
        color(x + half, y, half);
        color(x + half, y + half, half);
    }
}

int main() 
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    color(0, 0, N);
    printf("%d\n%d", w, b);
   
    return 0;
}