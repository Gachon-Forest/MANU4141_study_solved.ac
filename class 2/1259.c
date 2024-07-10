/*
Date: 7/8
No: 1259
Tier: B - 1
Name: 팰린드롬수
Language: C 99
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char num[6];
    
    while (scanf("%s", num) && num[0] != '0') 
    {
        int len = strlen(num), palin = 1;
        
        for (int i = 0; i < len/2; i++)
           
            if (num[i] != num[len - 1 - i])
            {
                palin = 0;
                break;
            }
        puts(palin ? "yes" : "no");
    }
    return 0;
}
