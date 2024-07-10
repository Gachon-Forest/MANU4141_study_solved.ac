/*
Date: 7/8
No: 2609
Tier: B - 1
Name: 최대공약수와 최소공배수
Language: C 99
*/

#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d", &a, &b);

    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        c = i;
    }

    printf("%d\n", c);
    printf("%d", a * b / c);
   
    return 0;
}