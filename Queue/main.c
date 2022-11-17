#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
typedef int item;

typedef struct Queue {
    int front, rear;
    item Data[MAX];
    int count;
} Queue;

void QueueInit(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;

}

bool IsEmpty(Queue Q)
{
    return(Q.count == 0);
}

bool IsFull(Queue Q)
{
    return(Q.count == MAX);
}

void Push(Queue *Q, item val)
{
   
    if (IsFull(*Q)) 
    {
        printf("Queue is full!!!\n");
    }
    else{
        Q->rear++;
        Q->Data[Q->rear] = val;
        Q->count++;
    }
    
}

item Pop(Queue *Q)
{
    if (IsEmpty(*Q))
    {
        printf("Queue is empty!!!\n");
    }
    else{
        item val = Q->Data[Q->front];
        for (int i = Q->front; i < Q->rear; i++)
        {
            Q->Data[i] = Q->Data[i+1];
        }
        Q->Data[Q->rear] = NULL;
        Q->rear--;
        Q->count--;
        return val;
    }
}

Queue Q;
void main()
{
QueueInit(&Q);
Push(&Q, 10);
Push(&Q, 1);
Push(&Q, 0);

}