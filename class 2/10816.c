/*
Date: 7/16
No: 10816
Tier: s - 4
Name: 숫자 카드 2
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000001

int main() 
{
    int N, M;
    scanf("%d", &N);
    
    int* cards = (int*)malloc(N * sizeof(int));
    int* count = (int*)calloc(2 * MAX, sizeof(int)); 
    
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &cards[i]);
        count[cards[i] + MAX]++;
    }

    scanf("%d", &M);
    
    int* queries = (int*)malloc(M * sizeof(int));
    
    for (int i = 0; i < M; i++) 
    {
        scanf("%d", &queries[i]);
    }

    for (int i = 0; i < M; i++) 
    {
        printf("%d ", count[queries[i] + MAX]);
    }
    printf("\n");

    free(cards);
    free(count);
    free(queries);
    
    return 0;
}