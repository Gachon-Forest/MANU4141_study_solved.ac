/*
Date: 8/5
No: 1927
Tier: s - 2
Name: �ּ� ��
Language: C 99
*/

#include <stdio.h> // ���� Ʈ��

int Heap[100001] = {}, size = 0;

void push(int n)   //���� ���� �θ𺸴� �۾��������� �θ� �ڽ� ����
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

	for (int child = 2; child <= size; child *= 2) // �θ� �ڽ� ��ġ ����
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