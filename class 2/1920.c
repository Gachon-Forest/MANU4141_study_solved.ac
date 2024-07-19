/*
Date: 7/19
No: 1920
Tier: s - 4
Name: 수 찾기
Language: C 99
*/

// 이진 탐색 사용
// 퀵 정렬

#include <stdio.h>
#include <stdlib.h>

int arrN[100000];
int arrM[100000];

int binary_search(int arr[], int key, int size) 
{
    int front = 0, back = size - 1;

    while (front <= back) 
    {
        int pivot = (front + back) / 2;
        if (arr[pivot] == key) 
        {
            return 1;
        } else if (arr[pivot] < key) 
        {
            front = pivot + 1;
        } else 
        {
            back = pivot - 1;
        }
    }
    return 0;
}

int cmp(const void *a, const void *b) 
{
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    return (int_a > int_b) - (int_a < int_b);
}

int main() 
{
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arrN[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) 
    {
        scanf("%d", &arrM[i]);
    }
    
    qsort(arrN, N, sizeof(int), cmp);

    for (int i = 0; i < M; i++) 
    {
        printf("%d\n", binary_search(arrN, arrM[i], N));
    }

    return 0;
}