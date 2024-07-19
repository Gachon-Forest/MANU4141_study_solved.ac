/*
Date: 7/17
No: 11650
Tier: s - 5
Name: 좌표 정렬하기
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    int *point1 = (int *)a;
    int *point2 = (int *)b;

    if (point1[0] != point2[0])
        return point1[0] - point2[0];
    else
        return point1[1] - point2[1];
}

int main()
 {
    int N;
    scanf("%d", &N);

    int (*points)[2] = malloc(N * sizeof(*points));

    for (int i = 0; i < N; i++) 
    {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    qsort(points, N, sizeof(points[0]), compare);

    for (int i = 0; i < N; i++) 
    {
        printf("%d %d\n", points[i][0], points[i][1]);
    }

    free(points);

    return 0;
}

/*
Date: 7/17
No: 11650
Tier: s - 5
Name: 좌표 정렬하기
Language: c99


#include <stdio.h>
#include <stdlib.h>

int compare(const voida, const void b) 
{
    intpoint1 = (int )a;
    intpoint2 = (int )b;

    if (point1[0] != point2[0])
        return point1[0] - point2[0];
    else
        return point1[1] - point2[1];
}

int main()
 {
    int N;
    scanf("%d", &N);

    int (points)[2] = malloc(N * sizeof(*points));

    for (int i = 0; i < N; i++) 
    {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    qsort(points, N, sizeof(points[0]), compare);

    for (int i = 0; i < N; i++) 
    {
        printf("%d %d\n", points[i][0], points[i][1]);
    }

    free(points);

    return 0;
} 
*/