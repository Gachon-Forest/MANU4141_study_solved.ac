/*
Date: 7/8
No: 10845
Tier: s - 4
Name: 큐
Language: C 99
*/

#include <stdio.h>
#include <string.h>
#define Q_SIZE 10001

int Q[Q_SIZE];
int front_index = 0;
int back_index = 0;

void push(int x) 
{
    Q[back_index++] = x;
}

int pop() 
{
    if (front_index == back_index) 
    {
        return -1;
    }
    else 
    {
        return Q[front_index++];
    }
}

int size() 
{
    return back_index - front_index;
}

int empty() 
{
    return front_index == back_index;
}

int front() 
{
    if (empty()) 
    {
        return -1;
    } 
    else 
    {
        return Q[front_index];
    }
}

int back() 
{
    if (empty()) 
    {
        return -1;
    } 
    else 
    {
        return Q[back_index - 1];
    }
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
        } 
        else if (strcmp(command, "pop") == 0) 
        {
            printf("%d\n", pop());

        } 
        else if (strcmp(command, "size") == 0) 
        {
            printf("%d\n", size());
        } 
        else if (strcmp(command, "empty") == 0) 
        {
            printf("%d\n", empty());
        } 
        else if (strcmp(command, "front") == 0) 
        {
            printf("%d\n", front());
        } 
        else if (strcmp(command, "back") == 0) 
        {
            printf("%d\n", back());
        }
    }
    return 0;
}
