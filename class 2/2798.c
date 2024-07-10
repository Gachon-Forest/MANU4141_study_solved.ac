/*
Date: 7/8
No: 2798
Tier: B - 2
Name: 블랙잭
Language: C 99
*/

#include <stdio.h>

int main() 
{
    int arr[100];
    int n, m;
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    int result = 0;
    int sum = 0;

    for (int i = 0; i < n-2; i++) 
    {
        for (int j = i+1; j < n-1; j++) 
        {
            for (int k = j+1; k < n; k++) 
            {
                sum = arr[i] + arr[j] + arr[k];
                
                if (sum > result && sum <= m) 
                    result = sum;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
