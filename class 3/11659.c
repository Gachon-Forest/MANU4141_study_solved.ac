/*
Date: 8/5
No: 11659
Tier: s - 3
Name: 구간 합 구하기 4
Language: C 99
*/

#include <stdio.h>

int main() 
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    int arr[N + 1];  
    int S[N + 1];    

    S[0] = 0; 
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        S[i] = S[i-1] + arr[i];
    }

    for (int k = 0; k < M; k++) 
    {
        int i, j;
    
        scanf("%d %d", &i, &j);
        printf("%d\n", S[j] - S[i-1]);
    }
    return 0;
}