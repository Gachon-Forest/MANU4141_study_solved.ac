/*
Date: 7/8
No: 1546
Tier: B - 1
Name: 평균
Language: C 99
*/

#include <stdio.h>

int main() {
	int n, score;
	int max = 0;
	int total = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &score);
		total += score;
		
		if (score > max) {
			max = score;
		}
	}
	printf("%f\n", 100.0 * total / n / max);
}
