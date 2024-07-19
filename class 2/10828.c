/*
Date: 7/19
No: 10828
Tier: s - 4
Name: 스택
Language: C 99
*/

#include <stdio.h>
#include <string.h>
#define STACK_SIZE 10001

int top_index = -1;
int stack[STACK_SIZE];

void push(int x) 
{
    stack[++top_index] = x;
}

int is_empty() 
{
    return top_index == -1;
}

int pop() 
{
    return is_empty() ? -1 : stack[top_index--];
}

int top() 
{
    return is_empty() ? -1 : stack[top_index];
}

int size() 
{
    return top_index + 1;
}

int main() 
{
    int N, push_data;
    char command[6]; 

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) 
        {
            scanf("%d", &push_data);
            push(push_data);

        } else if (strcmp(command, "pop") == 0) 
        {
            printf("%d\n", pop());

        } else if (strcmp(command, "empty") == 0) 
        {
            printf("%d\n", is_empty());

        } else if (strcmp(command, "size") == 0) 
        {
            printf("%d\n", size());

        } else if (strcmp(command, "top") == 0) 
        {
            printf("%d\n", top());
        }
    }
    return 0;
}