/*
Date: 8/3
No: 18870
Tier: s - 2
Name: 좌표 압축
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

int main() 
{
    int N;
    scanf("%d", &N);
    
    int coordinates[MAX_N];
    int sorted[MAX_N];
    int compressed[MAX_N];
    int rank[MAX_N];
    
    for(int i = 0; i < N; i++) 
    {
        scanf("%d", &coordinates[i]);
        sorted[i] = coordinates[i];
    }
    
    qsort(sorted, N, sizeof(int), compare); // 좌표 정렬
                                            // 좌표 압축, 중복 제거, 값들 할당
    int index = 0;
    rank[sorted[0]] = index;                
    
    for(int i = 1; i < N; i++) 
    {
        if(sorted[i] != sorted[i-1]) 
        {
            index++;
        }
        rank[sorted[i]] = index;
    }
    
    for(int i = 0; i < N; i++) 
    {
        compressed[i] = rank[coordinates[i]];
    }
    
    for(int i = 0; i < N; i++) 
    {
        printf("%d ", compressed[i]);
    }
    return 0;
}