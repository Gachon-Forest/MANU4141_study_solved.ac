/*
Date: 7/17
No: 2164
Tier: s - 4
Name: 카드2
Language: c99
*/

#include <stdio.h>
#define size 500000

int main()
{
    int n, i, front = 0, back;
    int Q[size];

    scanf("%d", &n);

    for (i = 0; i < n; i++) Q[i] = i + 1;
    back = n - 1;

    while (1) 
    {
        front = (front + 1) % n;

        if (back == front) break; 

        back = (back + 1) % n;

        Q[back] = Q[front];

        front = (front + 1) % n;

        if (back == front) break; 
    }
    printf("%d", Q[back]); 

    return 0;
}