/*
Date: 8/5
No: 1927
Tier: s - 2
Name: 최소 힙
Language: C 99
*/

#include <stdio.h> // 이중 트리

int Heap[100001] = {}, size = 0;

void push(int n)   //현재 값이 부모보다 작아질때까지 부모 자식 스왑
{
	int cur = ++size;

	while (cur > 1 && Heap[cur / 2] > n)
	{
		Heap[cur] = Heap[cur / 2];
		cur /= 2;
	}
	Heap[cur] = n;
}

int pop()
{
	if (size == 0)
		return 0;

	int root = Heap[1];
	int temp = Heap[size--];
	int parent = 1;

	for (int child = 2; child <= size; child *= 2) // 부모 자식 위치 변경
	{
		if (child < size && Heap[child] > Heap[child + 1])
			child++;

		if (temp <= Heap[child])
			break;

		Heap[parent] = Heap[child];
		parent = child;
	}
	Heap[parent] = temp;
	return root;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			printf("%d\n", pop());
		else
			push(n);
	}
	return 0;
}