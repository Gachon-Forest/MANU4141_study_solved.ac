/*
Date: 7/17
No: 9012
Tier: s - 4
Name: 괄호
Language: c99
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    int n;

    scanf("%d", &n);

    while (n--)
    {
        char str[51];
        int c = 0, b = 1;

        scanf("%s", str);

        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == '(')
            {
                c++;
            }
            else
            {
                c--;
            }
            if (c < 0)
            {
                b = 0;
                break;
            }
        }

        if (b && c == 0)
        {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}