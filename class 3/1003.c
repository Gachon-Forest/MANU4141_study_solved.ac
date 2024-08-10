/*
Date: 7/27
No: 1003
Tier: s - 3
Name: 피보나치 함수
Language: C 99
*/


#include <stdio.h>

int fi[41] = { 0, 1, 1 };

int main() 
{
    for (int i = 3; i < 41; i++) 
    {
        fi[i] = fi[i - 1] + fi[i - 2];
    }

    int T;
    int N;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) 
    {
        scanf("%d", &N);
        if (N == 0) 
        {
            printf("1 0\n");
        } 
        else if (N == 1) 
        {
            printf("0 1\n");
        } 
        else
        {
            printf("%d %d\n", fi[N - 1], fi[N]);
        }
    }
    return 0;
}