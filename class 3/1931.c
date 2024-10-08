/*
Date: 8/5
No: 1931
Tier: s - 1
Name: 회의실 배정
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} greed;

int compare(const void *a, const void *b)
{
	greed A = *(greed *)a;
	greed B = *(greed *)b;
	
    if (A.y > B.y)
		{
            return 1;
        }
	else if (A.y == B.y)
	{
		if (A.x > B.x)
        {
			return 1;
        }
        else
		{
            return -1;
        }
	}
	else
	{
    	return -1;
    }
}

int main()
{
	greed arr[100010];
	int i, j, n, count;
	i = 0;
	
    scanf("%d", &n);
	
    while (i < n)
	{
		scanf("%d %d", &arr[i].x ,&arr[i].y);
		i++;
	}
	
    qsort(arr, n, sizeof(greed), compare);

	i = 1;
	j = 0;
	count = 1; 

	while (i < n)
	{
		if (arr[j].y <= arr[i].x) 
		{
			j = i; 
			count++; 
		}
		i++;
	}
	printf("%d", count);
}