/*
Date: 7/8
No: 1978
Tier: B - 2
Name: 소수 찾기
Language: C 99
*/

#include <stdio.h>
int main()
{
    int N;
    int count = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
    {
        int num;

        scanf("%d", &num);

        if (num > 1) 
        {
            count++;

            for (int j = 2; j < num; j++) 
            {
          
                if (num % j == 0) 
                {
                
                    count--;
                
                    break;
                }
            }
        }
    }

    printf("%d", count);

    return 0;
}