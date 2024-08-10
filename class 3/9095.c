/*
Date: 7/29
No: 9095
Tier: s - 3
Name: 1, 2, 3 더하기
Language: C 99
*/

#include <stdio.h>

int dp[11]={1,2,4}; // dp는 점화식

int main()
{
    int t,n;

    for(int i=3;i<11;i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n-1]);
    }
    return 0;
}