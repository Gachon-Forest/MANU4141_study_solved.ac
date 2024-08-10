/*
Date: 7/27
No: 1463
Tier: s - 3
Name: 1로 만들기
Language: C 99
*/

#include <stdio.h> // dp가 점화식

int min(int a, int b) 
{
    return a < b ? a : b;
}

int main() 
{
    int dp[1000001] = {0};
    int i, n;
    
    scanf("%d", &n);
    
    dp[2] = 1;
    dp[3] = 1;
    
    for (i = 4; i <= n; i++) 
    {
        dp[i] = dp[i - 1] + 1;
        
        if (i % 3 == 0) 
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        
        if (i % 2 == 0) 
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    printf("%d\n", dp[n]);
    
    return 0;
}