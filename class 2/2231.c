/*
Date: 7/10
No: 1978
Tier: B - 2
Name: 분해합
Language: C 99
*/

#include <stdio.h>

int main()
{
    int N;
    
    scanf("%d", &N);

    for (int i = 1; i < N; i++)
    {
        int T = i;
        int num = i;

        while (T > 0)
        {
            num += T % 10;
            T /= 10;
        }

        if (num == N)
        {
            printf("%d", i);
            N = 0;
            break;
        }
    }
    if (N != 0)
    
    printf("0");

    return 0;
}