/*
Date: 7/11
No: 2292
Tier: B - 2
Name: 벌집
Language: C 99
*/

#include <stdio.h>

int main()
{
    int n, i = 2, j = 5, k = 2;
    
    scanf("%d", &n);
    if(n == 1)
    {
        printf("%d", 1);
        
        return 0;
    }
    while(1)
    {
        if(i <= n && i + j >= n)
        {
            printf("%d", k);
            break;
        }
        i = i + j + 1;
        j += 6;
        k++;
    }
    return 0;
}