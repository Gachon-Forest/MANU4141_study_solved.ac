/*
Date: 8/9
No: 7576
Tier: g - 5
Name: �丶�� 
Language: C 99
*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct _Queue 
{
	int x;       // �� ��ġ
	int y;       // �� ��ġ
	int order;   // ��¥ (�� ��°�� �ʹ� ��������)
} 
Queue;

int dy[4] = { 0, 1, 0, -1 }; // �� �̵� ���� 
int dx[4] = { 1, 0, -1, 0 }; // �� �̵� ���� 
 
int N, M;        // ������ ũ��
int front, back; // ť�� �հ� �� �ε���

void BFS(int** box, Queue* q, int y, int x);
 
int main() 
{
	int i, j;
	scanf("%d %d", &M, &N);                      // ��(M)�� ��(N) �Է¹ޱ�
	
	int** box = (int**)calloc(N, sizeof(int*));  // ���� ���� �Ҵ�
	
    for (i = 0; i < N; i++)
	{
		box[i] = (int*)calloc(M, sizeof(int));
	}
 
	int total = N * M;                                    // ��ü ĭ ��
	Queue* q = (Queue*)calloc(N * M + 1, sizeof(Queue));  // ť ���� �Ҵ�
	front = 0, back = 0;                                  // ť�� �ʱⰪ ����
 
	for (i = 0; i < N; i++)
    {
		for (j = 0; j < M; j++) 
        {
			scanf("%d", &box[i][j]);     // ���� ���� �Է¹ޱ�
			
            if (box[i][j] == -1)         // �� ĭ�� ���
			{
				total--;
			}
            else if (box[i][j] == 1)     // ���� �丶���� ���
            {   
				back++;
				q[back].y = i;
				q[back].x = j;
				q[back].order = 0;       // �ʱ� ��¥�� 0
			}
		}
	}
	
	BFS(box, q, q[0].y, q[0].x);         // BFS Ž�� ����
 
	if (total != back)                   // ���� �丶�� ���� ��ü ĭ ���� �ٸ���
	{
		printf("-1");                    // -1 ���
	}
    
    else
	{
		printf("%d", q[back].order);     // ������ ���� �丶���� ��¥ ���
	}
	
    for (i = 0; i < N; i++)
	{
		free(box[i]);                    // ���� �Ҵ� �޸� ����
	}
    free(box);
	free(q);                             // ť �޸� ����
	
    return 0;
}
 
void BFS(int** box, Queue* q, int y, int x) 
{
	while (front < back)                 // ť�� �� ������ �ݺ�
    {              
		front++;                         // ť�� front�� �� ĭ �̵�
		
        for (int i = 0; i < 4; i++)      // �����¿� Ž��
        {    
			int ny = q[front].y + dy[i];
			int nx = q[front].x + dx[i];
			
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) // ������ ��� ���
			{
				continue;
			}

            if (!box[ny][nx])                       // ���� ���� �丶���� ���
            {                            
				back++;                             // ť�� back�� ������Ű�� �� ��ġ ����
				q[back].y = ny;
				q[back].x = nx;
				q[back].order = q[front].order + 1; // ��¥ ����
				box[ny][nx] = 1;                    // �ش� �丶�並 ���� ������ ǥ��
			}
		}
	}
}