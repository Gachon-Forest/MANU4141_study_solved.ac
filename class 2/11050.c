/*
Date: 7/8
No: 11050
Tier: B - 1
Name: 이항 계수 1
Language: C 99
*/

#include <stdio.h>

int main() {
    int a, b;
    int k1 = 1, k2 = 1, k3 = 1;

    scanf("%d %d", &a, &b);

    for (int i = 1; i <= a; i++) {
        k1 *= i;
    }

    for (int j = 1; j <= b; j++) {
        k2 *= j;
    }

    for (int n = 1; n <= (a - b); n++) {
        k3 *= n;
    }

    int binomial_coefficient = k1 / (k2 * k3);

    printf("%d\n", binomial_coefficient);

    return 0;
}