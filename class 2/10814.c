/*
Date: 7/13
No: 10814
Tier: s - 5
Name: 나이순 정렬
Language: C 99
*/

// 선택 정렬 시간 초과

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct age
{
    int age;
    char name[101];
};

struct age A[100000];

void selection_sort(struct age arr[], int n);

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
    {
        scanf("%d %s", &A[i].age, A[i].name);
    }

    selection_sort(A, N);

    for (int i = 0; i < N; i++) 
    {
        printf("%d %s\n", A[i].age, A[i].name);
    }
}

void selection_sort(struct age arr[], int n) 
{
    int i, j, min_idx;
    struct age temp;

    for (i = 0; i < n - 1; i++) 
    {
        
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j].age < arr[min_idx].age) 
            {
                min_idx = j;
            }
        }

        if (min_idx != i) 
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
*/

// 퀵소트
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct age
{
    int age;
    char name[101];
};

struct age A[100000];

int compare(const void* a, const void* b);

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
    {
        scanf("%d %s", &A[i].age, A[i].name);
    }

    qsort(A, N, sizeof(struct age), compare);

    for (int i = 0; i < N; i++) 
    {
        printf("%d %s\n", A[i].age, A[i].name);
    }
}

int compare(const void* a, const void* b) 
{
    return (*(struct age*)a).age - (*(struct age*)b).age;
}