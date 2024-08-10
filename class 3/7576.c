/*
Date: 8/9
No: 7576
Tier: g - 5
Name: 토마토 
Language: C 99
*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct _Queue 
{
	int x;       // 열 위치
	int y;       // 행 위치
	int order;   // 날짜 (몇 번째로 익는 차례인지)
} 
Queue;

int dy[4] = { 0, 1, 0, -1 }; // 행 이동 방향 
int dx[4] = { 1, 0, -1, 0 }; // 열 이동 방향 
 
int N, M;        // 상자의 크기
int front, back; // 큐의 앞과 뒤 인덱스

void BFS(int** box, Queue* q, int y, int x);
 
int main() 
{
	int i, j;
	scanf("%d %d", &M, &N);                      // 열(M)과 행(N) 입력받기
	
	int** box = (int**)calloc(N, sizeof(int*));  // 상자 동적 할당
	
    for (i = 0; i < N; i++)
	{
		box[i] = (int*)calloc(M, sizeof(int));
	}
 
	int total = N * M;                                    // 전체 칸 수
	Queue* q = (Queue*)calloc(N * M + 1, sizeof(Queue));  // 큐 동적 할당
	front = 0, back = 0;                                  // 큐의 초기값 설정
 
	for (i = 0; i < N; i++)
    {
		for (j = 0; j < M; j++) 
        {
			scanf("%d", &box[i][j]);     // 상자 상태 입력받기
			
            if (box[i][j] == -1)         // 빈 칸인 경우
			{
				total--;
			}
            else if (box[i][j] == 1)     // 익은 토마토인 경우
            {   
				back++;
				q[back].y = i;
				q[back].x = j;
				q[back].order = 0;       // 초기 날짜는 0
			}
		}
	}
	
	BFS(box, q, q[0].y, q[0].x);         // BFS 탐색 시작
 
	if (total != back)                   // 익은 토마토 수가 전체 칸 수와 다르면
	{
		printf("-1");                    // -1 출력
	}
    
    else
	{
		printf("%d", q[back].order);     // 마지막 익은 토마토의 날짜 출력
	}
	
    for (i = 0; i < N; i++)
	{
		free(box[i]);                    // 동적 할당 메모리 해제
	}
    free(box);
	free(q);                             // 큐 메모리 해제
	
    return 0;
}
 
void BFS(int** box, Queue* q, int y, int x) 
{
	while (front < back)                 // 큐가 빌 때까지 반복
    {              
		front++;                         // 큐의 front를 한 칸 이동
		
        for (int i = 0; i < 4; i++)      // 상하좌우 탐색
        {    
			int ny = q[front].y + dy[i];
			int nx = q[front].x + dx[i];
			
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) // 범위를 벗어난 경우
			{
				continue;
			}

            if (!box[ny][nx])                       // 익지 않은 토마토인 경우
            {                            
				back++;                             // 큐의 back을 증가시키고 새 위치 저장
				q[back].y = ny;
				q[back].x = nx;
				q[back].order = q[front].order + 1; // 날짜 증가
				box[ny][nx] = 1;                    // 해당 토마토를 익은 것으로 표시
			}
		}
	}
}